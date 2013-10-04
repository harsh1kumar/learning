/*
 * This is the new way to use connect() introduced for IPv6. This is the easier 
 * method. 
 * NOTE: The old method can be used for both IPv4 & IPv6.
 * NOTE2 : Sample Code, will not compile
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <errno.h>

#define SERV_PORT ("80")

int main(int argc, char * argv[])
{
	int retval;
	int servfd;
	struct addrinfo hints, * servinfo;

	memset(&hints, 0, sizeof hints);
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;

	if ((retval = getaddrinfo("www.example.com", SERV_PORT, &hints, &servinfo)) != 0) {
		fprintf(stderr,"getaddrinfo() error : %s\n", gai_strerror(retval));
		exit(1);
	}

	if ((servfd = socket(servinfo->ai_family, servinfo->ai_socktype, servinfo->ai_protocol)) != 0) {
		fprintf(stderr, "socket() failed : %s\n", strerror(errno));
		freeaddrinfo(servinfo);
		exit(2);
	}

	if (connect(servfd, servinfo->ai_addr, sizeof servinfo->ai_addrlen) != 0) {
		fprintf(stderr, "connect() failed : %s", strerror(errno));
		freeaddrinfo(servinfo);
		exit(3);
	}


	--- Do some operations here ---


	freeaddrinfo(servinfo);

	return 0;
}
