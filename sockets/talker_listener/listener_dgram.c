/* 
 * A listener to recieve the string that talker sends over a datagram socket connection.
 * Uses Stream Socket i.e UDP
 * NOTE: This listener works with its own custom talker_dgram.c program.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>

#define MYPORT ("4001")
#define MAX_BUFF_LEN (100)

void * get_talker_addr(struct sockaddr * sa)
{
	if (sa->sa_family == AF_INET)
		return &(((struct sockaddr_in *)sa)->sin_addr);
	else
		return &(((struct sockaddr_in6 *)sa)->sin6_addr);

}

int main(int argc, char * argv[])
{
	int retval;
	int servfd;
	int yes = 1;
	int recv_len;
	char recv_buff[MAX_BUFF_LEN];
	struct addrinfo hints, * servinfo, *p;
	struct sockaddr_storage talker_addr;
	char talker_addr_str[INET6_ADDRSTRLEN];
	socklen_t talker_addr_len;

	memset(&hints, 0, sizeof hints);
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_DGRAM;
	hints.ai_flags = AI_PASSIVE;

	if ((retval = getaddrinfo(NULL, MYPORT, &hints, &servinfo)) != 0) {
		fprintf(stderr, "getaddrinfo : %s\n", gai_strerror(retval));
		exit(1);
	}

	for(p = servinfo; p != NULL; p = p->ai_next) {
		if ((servfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
			perror("socket");
			continue;
		}

		/* Making socket i.e. the port reusable to prevent bind error */
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
		fprintf(stderr, "Failed to bind\n");
		exit(2);
	}

	printf("Waiting for talker string...\n");

	talker_addr_len = sizeof talker_addr;
	if ((recv_len = recvfrom(servfd, recv_buff, MAX_BUFF_LEN, 0, 
			(struct sockaddr *)&talker_addr, &talker_addr_len)) == -1) {
		perror("recvfrom");
		close(servfd);
		exit(3);
	}

	inet_ntop(talker_addr.ss_family, get_talker_addr((struct sockaddr *)&talker_addr), 
				talker_addr_str, sizeof talker_addr_str);

	printf("Recieved following string from %s\n", talker_addr_str);
	printf("\t%s Bytes = %d\n", recv_buff, recv_len);

	close(servfd);

	return 0;
}


