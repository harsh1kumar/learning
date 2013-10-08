/*
 * Simple way of sending a float over network. 
 * This server receives the float
 * DANGER: Not portable!!
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>

#define LISTEN_PORT ("4000")
#define LISTEN_QUEUE (5)

void do_server_stuff(int servfd)
{
	int clientfd;
	struct sockaddr_storage clientaddr;
	socklen_t clientaddrlen = sizeof clientaddr;

	float recv_buff;
	int buff_len = sizeof recv_buff;

	while(1) {
		if ((clientfd = accept(servfd, (struct sockaddr *)&clientaddr, &clientaddrlen)) == -1) {
			perror("accept");
			close(servfd);
			exit(4);
		}

		printf("New Connection recieved\n");

		buff_len = recv(clientfd, &recv_buff, buff_len, 0);
		if (buff_len == 0)
			printf("Connection closed\n");
		else if (buff_len == -1)
			perror("recv");
		else
			printf("Recieved float = %f\n", recv_buff);

		close(clientfd);
		printf("Done, closing connection\n");
	}
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
		if((servfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
			perror("socket");
			continue;
		}

		/* To allow reuse of socket */
		if (setsockopt(servfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1) {
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

	do_server_stuff(servfd);

	close(servfd);

	return 0;
}



