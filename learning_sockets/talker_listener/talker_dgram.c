/* 
 * A talker to send the string that user enters over a datagram socket connection.
 * Uses Stream Socket i.e UDP
 * NOTE: This talker works with its own custom listener_dgram.c program.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>

#define MYPORT "4001"
#define VAL_ARGC 2

int main(int argc, char * argv[])
{
	int retval;
	int servfd;
	int bytesent;
	struct addrinfo hints, * servinfo, *p;
	char * send_buff = NULL;
	int str_len, buff_len;

	if (argc != VAL_ARGC) {
		fprintf(stderr,"Usage : %s [Destination IP/hostname]\n", argv[0]);
		exit(1);
	}

	memset(&hints, 0, sizeof hints);
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_DGRAM;

	if ((retval = getaddrinfo(argv[1], MYPORT, &hints, &servinfo)) != 0) {
		fprintf(stderr, "getaddrinfo : %s\n", gai_strerror(retval));
		exit(1);
	}

	for(p = servinfo; p != NULL; p = p->ai_next) {
		if ((servfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
			perror("socket");
			continue;
		}
		break;
	}

	if (p == NULL) {
		fprintf(stderr, "Failed to create socket\n");
		freeaddrinfo(servinfo);
		exit(1);
	}

	printf("\nEnter String to send: ");
	if ( (str_len = getline(&send_buff, &buff_len, stdin)) == -1) {
		perror("getline");
		close(servfd);
		freeaddrinfo(servinfo);
		exit(1);
	}

	if (sendto(servfd, send_buff, str_len + 1, 0,p->ai_addr, p->ai_addrlen) == -1) {
		perror("sendto");
		free(send_buff);
		close(servfd);
		freeaddrinfo(servinfo);
		exit(1);
	}

	printf("Sent the following string to %s\n\t%s\n", argv[1], send_buff);
	free(send_buff);

	close(servfd);
	freeaddrinfo(servinfo);

	return 0;
}


