/*
 * To demonstrate the use of select()
 * A multi-user chat server
 * Users can connect using following command - 
 * 	$ telnet [hostname/IP] 4002
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/select.h>
#include <arpa/inet.h>

#define LISTEN_PORT ("4002")
#define LISTEN_QUEUE (5)
#define MAX_STR_LEN (100)

/*
 * Function to accept new connections and to send & recieve chat messages.
 */

void * get_addr(struct sockaddr * addr);
void accept_new_conn(int servfd, fd_set * p_masterfd_set, int * p_max_fd);
void handle_recv_data(int servfd, int clientfd, fd_set * p_masterfd_set,
			int * p_max_fd);
void do_chat(int servfd);

void * get_addr(struct sockaddr * addr)
{
	if (addr->sa_family == AF_INET)
		return &((struct sockaddr_in *)addr)->sin_addr;
	else
		return &((struct sockaddr_in6 *)addr)->sin6_addr;		
}

void accept_new_conn(int servfd, fd_set * p_masterfd_set, int * p_max_fd)
{
	int clientfd;
	char clientaddr_str[INET6_ADDRSTRLEN];

	struct sockaddr_storage clientaddr;
	socklen_t clientaddrlen = sizeof clientaddr;

	if ((clientfd = accept(servfd, (struct sockaddr *)&clientaddr, 
				&clientaddrlen)) == -1) {
		perror("accept");
		close(servfd);
		exit(5);
	}
					
	printf("New connection from %s\n", inet_ntop(clientaddr.ss_family,
				get_addr((struct sockaddr *)&clientaddr), 
				clientaddr_str,INET6_ADDRSTRLEN));

	FD_SET(clientfd, p_masterfd_set);
	*p_max_fd = (clientfd > *p_max_fd) ? clientfd : *p_max_fd;

	return;
}

void handle_recv_data(int servfd, int clientfd, fd_set * p_masterfd_set, 
			int * p_max_fd)
{
	char recv_str[MAX_STR_LEN];
	char send_str[MAX_STR_LEN];
	int str_len;
	int j;
	int new_max_fd = 0;

	str_len = recv(clientfd, recv_str, sizeof recv_str, 0);
	if (str_len <= 0) {
		if (str_len == 0)
			printf("Connection on socket %d closed\n", clientfd);
		else
			perror("recv");

		FD_CLR(clientfd, p_masterfd_set);
		if (clientfd == *p_max_fd) {
			for(j=0; j <= *p_max_fd; j++)
				if (FD_ISSET(j, p_masterfd_set) && j > new_max_fd)
					new_max_fd = j;
			*p_max_fd = new_max_fd;
		}
		close(clientfd);
	}
	else {
		recv_str[str_len-2] = '\0';
		sprintf(send_str, "[%d]> %s\n", clientfd, recv_str);
		for(j=0; j<=*p_max_fd; j++) {
			if (j != servfd && j != clientfd && FD_ISSET(j, p_masterfd_set)) {
				if (send(j, send_str, strlen(send_str), 0) == -1) {
					perror("send");
				}
			}
		}
	}
}

void do_chat(int servfd)
{
	fd_set masterfd_set, readfd_set;
	int max_fd;
	struct timeval timeout;
	int no_of_read_ready;

	int i;

	FD_ZERO(&masterfd_set);
	FD_ZERO(&readfd_set);

	FD_SET(servfd, &masterfd_set);
	max_fd = servfd;

	while(1) {
		readfd_set = masterfd_set;
		timeout.tv_sec = 2;
		timeout.tv_usec = 500000;
		if (select(max_fd + 1, &readfd_set, NULL, NULL, &timeout) == -1) {
			perror("select");
			close(servfd);
			exit(4);
		}

		for(i = 0; i <= max_fd; i++) {
			if (FD_ISSET(i, &readfd_set)) {
				if(i == servfd) {
					/* New Connection recieved */ 
					accept_new_conn(servfd, &masterfd_set, 
							&max_fd);
				}
				else {
					/* Data recieved on a connection */
					handle_recv_data(servfd, i, 
							&masterfd_set, &max_fd);
				}
			}
		}
	}

	return;
}

int main(int agrc, char * argv[])
{
	int servfd;
	int retval;
	int yes = 1;
	struct addrinfo hints, * servinfo, * p;

	memset(&hints, 0, sizeof hints);
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;

	/* Getting address info */
	if ((retval = getaddrinfo(NULL, LISTEN_PORT, &hints, &servinfo)) != 0) {
		fprintf(stderr, "getaddrinfo : %s\n", gai_strerror(retval));
		exit(1);
	}

	for (p = servinfo; p != NULL; p = p->ai_next) {
		if((servfd = socket(p->ai_family, p->ai_socktype, 
					p->ai_protocol)) == -1) {
			perror("socket");
			continue;
		}

		/* To allow reuse of socket */
		if (setsockopt(servfd, SOL_SOCKET, SO_REUSEADDR, &yes, 
					sizeof(int)) == -1) {
			perror("setsockopt");
			close(servfd);
			continue;
		}

		if (bind(servfd, p->ai_addr, p->ai_addrlen) == -1) {
			perror("bind");
			close(servfd);
			continue;
		}
		break;
	}

	freeaddrinfo(servinfo);
	if (p == NULL) {
		fprintf(stderr, "Not able to bind\n");
		exit(2);
	}

	if (listen(servfd, LISTEN_QUEUE) == -1) {
		perror("listen");
		close(servfd);
		exit(3);
	}

	printf("Waiting for connections...\n");

	do_chat(servfd);

	close(servfd);

	return 0;
}



