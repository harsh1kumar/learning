/*
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>

#define REQ_ARGC (2)
#define MYPORT ("4000")

int main(int argc, char * argv[])
{
	int servfd;
	int retval;
	struct addrinfo hints, * servinfo, * p;

	if (argc != REQ_ARGC) {
		fprintf(stderr, "Usage : %s [hostname/IP]\n", argv[0]);
		exit(1);
	}

	memset(&hints, 0, sizeof hints);
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;

	/* Getting address info */
	if((retval = getaddrinfo(argv[1], MYPORT, &hints, &servinfo)) != 0) {
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(retval));
		exit(2);
	}

	/* Attempting creating a socket & connecting*/
	for(p = servinfo; p != NULL; p = p->ai_next) {
		if ((servfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
			perror("socket");
			continue;
		}

		if (connect(servfd, p->ai_addr, p->ai_addrlen) == -1) {
			perror("connect");
			close(servfd);
			continue;
		}
		break;
	}

	freeaddrinfo(servinfo); /* No longer needed */

	if (p == NULL) {
		fprintf(stderr,"Failed to connect\n");
		exit(3);
	}

	printf("Connected to the remote server - %s : %s\n", argv[1], MYPORT);

	/* recv() or send() */

	close(servfd);

	return 0;
}
