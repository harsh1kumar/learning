/*
 * To find file size
 */
#include <stdio.h>
#include <stdlib.h>

#define REQ_ARGC 2

int main(int argc, char * argv[])
{
	FILE * fp;
	char a_byte;

	if (argc != 2) {
		fprintf(stderr, "Usage: %s [filename]\n", argv[0]);
		exit(1);
	}

	if ((fp = fopen(argv[1], "r")) == NULL) {
		perror("fopen");
		exit(2);
	}

	fseek(fp, 0L, SEEK_END);
	printf("Size = %ld bytes\n", ftell(fp));

	fclose(fp);

	return 0;
}
