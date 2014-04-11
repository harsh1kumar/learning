/*
 * tail
 */

#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_N 10

int my_getline(char ** pline);
int read_lines(int n);
void write_lines(int n, int line_no);

/*
 * Modified Curcular Queue
 * -----------------------
 *
 * If queue is full, it over-writes the 1st element in the queue
 */

char ** lines; /* A circular queue of (char *) pointers */
int q_start = 0; /* Start of the queue */

int main(int argc, char *argv[])
{
	int n = DEFAULT_N; /* No. of lines from the end */
	int line_no;

	if (argc > 2)
	{
		printf("Usage: %s [-n]\n", *argv);
		return 1;
	}

	if (argc == 2)
	{
		if (*argv[1] != '-')
		{
			printf("Usage: %s [-n]\n", *argv);
			return 1;
		}
		n = atoi(++argv[1]); 	/* argv[1] will point to 1st char of argument 2.
					 * ++ will make it point to 2nd character. */
	}

	line_no = read_lines(n);
	write_lines(n, line_no);
}

#define ALLOC_STEP 10 /* Steps by which memory allocation size will be increased */

/*
 * Returns the size of the line or EOF. Allocates space for the line
 */
int my_getline(char ** pline)
{
	int c;
	int i;
	int allocated;

	i=0;
	allocated = 0;
	*pline = NULL;
	while((c=getchar()) != EOF && c != '\n')
	{
		if (i >= allocated-1)
		{
			allocated += ALLOC_STEP;
			*pline = (char *) realloc(*pline, allocated*sizeof(char));
			if (*pline == NULL)
			{
				fprintf(stderr, "Error: Not able to allocate space\n");
				return EOF;
			}
		}
		(*pline)[i++] = c;
	}

	if (c==EOF)
		return EOF;

	(*pline)[i] = '\0';
	return i;
}

/*
 * Returns the number of lines read
 */
int read_lines(int n)
{
	char * l;
	int line_len;
	int line_no;
	
	/* Allocate space for storing n pointers to n lines */
	lines = (char **)malloc(n*sizeof(char *));
	if (lines == NULL)
	{
		fprintf(stderr, "Error: Not able to allocate space\n");
		return 0;
	}

	/* Make all elements NULL */
	int i;
	for(i=0; i<n; ++i)
		lines[i] = NULL;
	
	line_no = 0;
	while((line_len = my_getline(&l)) != EOF)
	{
		if (line_len)
		{
			if (line_no < n)
				++line_no;

			if (q_start == n)
				q_start = 0;

			/* Before overwriting the previous pointer value, free the space allocated for that pointer.
			 * For previously empty elements, the value of pointer should be NULL which is set when queue is created.*/
			free(lines[q_start]);
			lines[q_start++] = l;
		}
	}

	return line_no;
}

void write_lines(int n, int line_no)
{
	if (line_no != n)
		q_start = 0; /* Queue is not full, start will be at 0 */

	printf("\n\nTail:\n\n");
	while(line_no--)
	{
		if (q_start == n)
			q_start = 0; /* Circulating the index */

		printf("%s\n", lines[q_start]);
		free(lines[q_start++]);
	}
	free(lines);
}

