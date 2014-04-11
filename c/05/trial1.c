/*
 * Sort lines
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100

int my_getline(char * line, int max_len);

int read_lines(char * plines[], int max_nlines);
void write_lines(char * plines[], int nlines);

void swap(char ** a, char ** b);
void my_qsort(char * plines[], int left, int right);

int main()
{
	int nlines; /* Number of lines */
	char * plines[MAX_LINES]; /* Pointers to lines */
	
	if ((nlines = read_lines(plines, MAX_LINES)) < 0)
	{
		fprintf(stderr, "Error: Lack of memory. Input is too large.\n");
		return 1;
	}

	my_qsort(plines, 0, nlines-1);
	write_lines(plines, nlines);

	return 0;
}

int my_getline(char * line, int max_len)
{
	int c;
	int i;

	i=0;
	while((c=getchar()) != EOF && c != '\n')
		if (i < max_len-1)
			line[i++] = c;

	if (c==EOF)
		return 0;

	line[i++] = '\0';
	return i;
}

#define MAX_LINE_LEN 100

int read_lines(char * plines[], int max_nlines)
{
	int nlines;
	char line[MAX_LINE_LEN];
	char line_len; /* Includes \0 character at the end */

	nlines = 0;
	while(line_len = my_getline(line, MAX_LINE_LEN))
	{
		/* line_len is when when line is empty - line will contain only \0 */
		if (line_len > 1)
		{
			if (nlines == max_nlines)
				return -1;

			plines[nlines] = (char *) malloc(sizeof(char) * line_len);
			if (plines[nlines] == NULL)
				return -1;

			strcpy(plines[nlines], line);
			++nlines;
		}
	}

	return nlines;
}

void write_lines(char * plines[], int nlines)
{
	int i;

	printf("\n\nSorted Lines:\n\n");
	for (i=0; i<nlines; ++i)
	{
		printf("%s\n", plines[i]);
		free(plines[i]);
	}
}

void swap(char ** a, char ** b)
{
	char * t = *a;
	*a = *b;
	*b = t;
}

void my_qsort(char * plines[], int left, int right)
{
	int last;

	if (left >= right)
		return;

	swap(&plines[left], &plines[(left+right)/2]);
	last = left;

	int i;
	for(i=left+1; i<=right; ++i)
		if (strcmp(plines[left],plines[i]) > 0)
			swap(&plines[++last], &plines[i]);

	swap(&plines[left], &plines[last]);
	my_qsort(plines, left, last-1);
	my_qsort(plines, last+1, right);
}

