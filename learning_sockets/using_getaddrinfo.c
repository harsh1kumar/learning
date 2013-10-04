/*
 * To learn how to use getaddrinfo() & see what it does
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
//#include <sys/types.h>
//#include <sys/socket.h>
//#include <netinet/in.h>
//#include <arpa/inet.h>

int main(int argc, char * argv[])
{
	int status = 0;
	struct addrinfo hints, * a_info, * lp;
	
	memset(&hints, 0, sizeof hints);
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;

	if (argc != 2) {
		printf("Usage: %s hostname\n", argv[0]);
		exit(1);
	}

	if ((status = getaddrinfo(argv[1], NULL, &hints, &a_info)) != 0) {
		fprintf(stderr, "Error occured in getaddrinfo() : %s\n", gai_strerror(status));
		exit(2);
	}
	else 
		printf("getaddrinfo was a success\n");

	for (lp = a_info; lp != NULL; lp = lp->ai_next)
	{
		int port = 0;
		char ipaddr[INET6_ADDRSTRLEN];
		if (lp->ai_family == AF_INET) {
			struct sockaddr_in * s_ad = (struct sockaddr_in *)lp->ai_addr;
			printf("Family = IPv4, ");
			inet_ntop(lp->ai_family, &(s_ad->sin_addr), ipaddr, INET_ADDRSTRLEN);
			port = s_ad->sin_port;
		}
		else if(lp->ai_family == AF_INET6) {
			struct sockaddr_in6 * s_ad = (struct sockaddr_in6 *)lp->ai_addr;
			printf("Family = IPv6, ");
			inet_ntop(lp->ai_family, &(s_ad->sin6_addr), ipaddr, INET6_ADDRSTRLEN);
			port = s_ad->sin6_port;
		}
		else {
			printf("Family = Other value!!\n");
			exit(3);
		}
		
		printf("Address = %s", ipaddr);
		printf(" : %d\n", port);
	}

	freeaddrinfo(a_info);

	return 0;
}
