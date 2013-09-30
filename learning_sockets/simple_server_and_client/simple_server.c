/* 
 * A server to send the string "Hello World!!\n" over a stream connection.
 * It can be tested by running following command -
 *	$ telnet remotehost 4000
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

	printf("Listening for connections...\n");

	while(1) {
		struct sockaddr_storage clientinfo;
		socklen_t cinfo_len = sizeof clientinfo;

		clientfd = accept(servfd, (struct sockaddr *)&clientinfo, &cinfo_len);
		if (clientfd == -1) {
			perror("accept");
			close(servfd);
			freeaddrinfo(servinfo);
			exit(1);
		}

		if (send(clientfd, "Hello World!!\n", 14, 0) == -1)
			perror("send");
		close(clientfd);
		sleep(1);
	}

	close(servfd);
	freeaddrinfo(servinfo);

	return 0;
}


