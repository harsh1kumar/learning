/*
 * This is the old way of doing things which was used for IPv4. 
 * But, this can also be used for IPv6
 */

#include <stdio.h>
#include <string.h>
#include <netdb.h>

#define SERV_PORT (80)

int main(int argc, char * argv[])
{
	/* NOTE : Checks for success & failure are missing in this code */
	
	int servfd;
	struct sockaddr_in servinfo;

	servinfo.sin_family = AF_INET;
	servinfo.sin_port = htons(SERV_PORT);
	memset(servinfo.sin_zero, 0, sizeof servinfo.sin_zero);

	/* sin_addr can be assigned to INADDR_ANY if you want it to be local address */
	inet_pton(AF_INET, "127.0.0.1", &servinfo.sin_addr);

	servfd = socket(PF_INET, SOCK_STREAM, 0);

	connect(servfd, (struct sockaddr *)&servinfo, sizeof servinfo);

	/*
	 * Do some operations here
	 */

	return 0;
}
