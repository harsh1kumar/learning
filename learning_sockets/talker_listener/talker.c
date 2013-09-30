/* 
 * A talker to send the string that user enters over a stream connection.
 * Uses Stream Socket i.e TCP
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <errno.h>

#define LISTENING_PORT ("4000")
#define LISTENING_QUEUE 1

int main(int argc, char * argv[])
{
	int retval;	
	int servfd, clientfd;
	int yes = 1;
	struct addrinfo hints, * servinfo, *p;

	memset(&hints, 0, sizeof hints);
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE; // Use host IP

	if((retval = getaddrinfo(NULL, LISTENING_PORT, &hints, &servinfo)) !=0 ) {
		fprintf(stderr, "getaddrinfo() failed : %s\n", gai_strerror(retval));
		exit(1);
	}

	for (p = servinfo; p != NULL; p = p->ai_next) {
		if ((servfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
			perror("socket");
			continue;
		}

		if (setsockopt(servfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1) {
			perror("setsockopt");
			close(servfd);
			freeaddrinfo(servinfo);
			exit(1);
        	}

		if ((bind(servfd, p->ai_addr, p->ai_addrlen)) == -1 ) {
			perror("bind");
			close(servfd);
			continue;
		}

		break;
	}

	if (p == NULL) {
		fprintf(stderr, "Failed to bind\n");
		freeaddrinfo(servinfo);
		exit(1);
	}

	
	if ((listen(servfd, LISTENING_QUEUE)) == -1 ) {
		perror("listen");
		close(servfd);
		freeaddrinfo(servinfo);
		exit(1);
	}

	while(1) {
		struct sockaddr_storage clientinfo;
		socklen_t cinfo_len = sizeof clientinfo;
		char * send_buff = NULL;
		unsigned int st_len, buff_len;

		printf("Listening for connections...\n\n");

		clientfd = accept(servfd, (struct sockaddr *)&clientinfo, &cinfo_len);
		if (clientfd == -1) {
			perror("accept");
			close(servfd);
			freeaddrinfo(servinfo);
			exit(1);
		}

		printf("Incoming connection accepted. Ready to send data...\n\n");
		while (1) {
			printf("Enter > ");
			
			if ((st_len = getline(&send_buff, &buff_len, stdin)) == -1) {
				perror("getline");
				exit(1);
			}

			/* The string sent is NULL terminated, so no need to 
			 * add null in the client buffer */
			if (send(clientfd, send_buff, st_len+1, 0) == -1)
				perror("send");
			if (!strcmp(send_buff, "q\n"))
				break;
		}
		printf("Connection closed\n\n");
		free(send_buff);
		close(clientfd);
	}

	close(servfd);
	freeaddrinfo(servinfo);

	return 0;
}


