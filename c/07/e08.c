/*
 * Print a set of files starting each file on a new page, with a title & a running page count for each file
 */

#include <stdio.h>
#include <string.h>

#define PAGELEN (80-3)
#define PAGEWIDTH 80

void printheader(int page, char * filename);
int printfile(FILE * fp, int page);

int main(int argc, char * argv[])
{
	FILE * fp;
	int page;
	int file;

	page = 1;
	for (file = 1; file < argc; ++file)
	{
		fp = fopen(argv[file], "r");
		if (fp == NULL)
		{
			fprintf(stderr, "Error: Unable to open file %s\n", argv[file]);
		}

		printheader(page, argv[file]);
		page = printfile(fp, page);
		printf("\f");
		++page;

		fclose(fp);
	}

	return 0;
}


int printfile(FILE * fp, int page)
{
	int c;
	int lines;
	int width;

	lines = 1;
	width = 0;
	while ( (c=getc(fp)) != EOF )
	{
		++width;
		if (c == '\t')
			width = ((width/8)+1) * 8;

		putchar(c);
		if (c == '\n')
		{
			width = 0;
			++lines;
		}
		else if (width >= PAGEWIDTH)
		{
			putchar('\n');
			width = 0;
			++lines;
		}

		if (lines > PAGELEN)
		{
			printf("\f");
			++page;
			lines = 0;
			printheader(page, "");
		}
	}

	return page;
}

void printheader(int page, char * filename)
{
	int len = 40;

	printf("Page %d\t|\t%s\n", page, filename);
	while(len--)
		printf("-");
	printf("\n\n");
}
