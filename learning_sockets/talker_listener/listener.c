/* 
 * A listener which prints whatever talker program sends
 * Uses Stream Socket i.e TCP
 * 	$ ./a.out [hostname/IP] [port]
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>

#define REQ_ARGC 3
#define RECV_BUFF_LEN 100

void client_work(int servfd);

void client_work(int servfd)
{
	int recv_len;
	char recv_buff[RECV_BUFF_LEN];

	do {
		recv_len = recv(servfd, recv_buff, RECV_BUFF_LEN, 0);
		if (recv_len == -1) {
			perror("recv");
			close(servfd);
			exit(1);
		}
		else if(recv_len == 0) {
			fprintf(stderr, "recv: Remote server closed the connection\n");
			close(servfd);
			exit(1);
		}
		else
			printf("%s", recv_buff);
	} while (strcmp(recv_buff,"q\n"));

	return;
}

int main(int argc, char * argv[])
{
	int servfd;
	int retval;
	struct addrinfo hints, * servinfo, * p;

	if (argc != REQ_ARGC) {
		fprintf(stderr, "Usage : %s [hostname/IP] [Port]\n", argv[0]);
		exit(1);
	}

	memset(&hints, 0, sizeof hints);
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;

	/* Getting address info */
	if((retval = getaddrinfo(argv[1], argv[2], &hints, &servinfo)) != 0) {
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(retval));
		exit(1);
	}

	/* Attempting creating a socket & connecting*/
	for(p = servinfo; p != NULL; p = p->ai_next) {
		if ((servfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
			perror("socket");
			continue;
		}

		if (connect(servfd, p->ai_addr, p->ai_addrlen) == -1) {
			perror("connect");
			continue;
		}
		break;
	}

	freeaddrinfo(servinfo); /* No longer needed */

	if (p == NULL) {
		fprintf(stderr,"Failed to connect\n");
		close(servfd);
		exit(1);
	}

	printf("Connected to the remote server - %s : %s\n", argv[1], argv[2]);

	client_work(servfd);

	close(servfd);

	return 0;
}
