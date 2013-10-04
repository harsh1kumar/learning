/* 
 * A talker to send the string that user enters over a stream connection.
 * Uses Stream Socket i.e TCP
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <errno.h>

#define MYPORT ("4000")
#define LISTENING_QUEUE (1)

void serve_actual_work(int clientfd);
void serve_incoming(int servfd);

void serve_actual_work(int clientfd)
{
	char * send_buff = NULL;
	unsigned int st_len, buff_len;

	printf("Incoming connection accepted. Ready to send data...\n\n");
	do {
		printf("Enter > ");
		
		if ((st_len = getline(&send_buff, &buff_len, stdin)) == -1) {
			perror("getline");
			exit(5);
		}

		/* The string sent is NULL terminated, so no need to 
		 * add null in the client buffer */
		if (send(clientfd, send_buff, st_len+1, 0) == -1)
			perror("send");

	} while (strcmp(send_buff, "q\n")); /* Entering string "q\n" will exit*/
	free(send_buff);

	return;
}

void serve_incoming(int servfd)
{
	int clientfd;
	struct sockaddr_storage clientinfo;
	socklen_t cinfo_len = sizeof clientinfo;

	printf("Waiting for connections...\n\n");
	clientfd = accept(servfd, (struct sockaddr *)&clientinfo, &cinfo_len);
	if (clientfd == -1) {
		perror("accept");
		close(servfd);
		exit(4);
	}

	serve_actual_work(clientfd);

	close(clientfd);
	printf("Connection closed\n\n");

	return;
}

int main(int argc, char * argv[])
{
	int retval;	
	int servfd;
	int yes = 1;
	struct addrinfo hints, * servinfo, *p;

	memset(&hints, 0, sizeof hints);
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE; // Use host IP

	if((retval = getaddrinfo(NULL, MYPORT, &hints, &servinfo)) !=0 ) {
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
			continue;
        	}

		if ((bind(servfd, p->ai_addr, p->ai_addrlen)) == -1 ) {
			perror("bind");
			close(servfd);
			continue;
		}

		break;
	}

	freeaddrinfo(servinfo); /* No longer needed */

	if (p == NULL) {
		fprintf(stderr, "Failed to bind\n");
		exit(2);
	}
	
	if ((listen(servfd, LISTENING_QUEUE)) == -1 ) {
		perror("listen");
		close(servfd);
		exit(3);
	}

	while(1)
		serve_incoming(servfd);

	close(servfd);
	return 0;
}


