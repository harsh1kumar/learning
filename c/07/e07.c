/*
 * Prints the line which contains the pattern. Take files from commandline, if none then take stdin
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void grep(FILE * fp, char * pattern, char * filename);

int main(int argc, char * argv[])
{
	FILE * fp;

	if (argc == 1)
	{
		printf("Usage: %s pattern [files]\n", *argv);
		exit(1);
	}
	
	else if (argc == 2)
		grep(stdin, *(argv+1), "");
	else
	{
		while(argc-- > 2)
		{
			fp = fopen(argv[argc], "r");
			if (fp == NULL)
			{
				fprintf(stderr, "Error: Unable to open file %s\n", argv[argc]);
				exit(2);
			}
			grep(fp, *(argv+1), argv[argc]);
			fclose(fp);
		}
	}

	return 0;
}

#define MAXLINE 200

void grep(FILE * fp, char * pattern, char * filename)
{
	char line[MAXLINE];
	int c;
	int len;

	c = 0;
	while (c != EOF)
	{
		/* Read a line */
		for (len = 0; len < MAXLINE-1 && (c=getc(fp)) != EOF && c != '\n'; ++len)
			line[len] = c;
		line[len] = '\0';

		if (strstr(line, pattern) != NULL)
			if (strlen(filename))
				printf("%s: %s\n", filename, line);
			else
				printf("%s\n", line);
	}
}
