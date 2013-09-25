/*
 * Simple use of gethostname()
 */

#include <stdio.h>
#include <errno.h>
#include <string.h>

#define RETURN_STR_LEN 40

int main(int argc, char * argv[])
{
	char hostname[RETURN_STR_LEN];
	
	if (gethostname(hostname, sizeof hostname) != 0) {
		fprintf(stderr,"gethostname() failed: %s\n", strerror(errno));
	}

	printf("Host Name of this machine is : %s\n", hostname);

	return 0;
}
