/*
 * To print hex form a file
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

	printf("Contents of the file %s are ->\n", argv[1]);
	while((a_byte = fgetc(fp)) != EOF) {
		printf("%02X ", a_byte);
	}
	printf("\n");

	fclose(fp);
	
	return 0;
}
