#include <stdio.h>

/*
 * Prints the longest line in input
 */

#define STR_SIZE 50

/*
 * Puts a line from input in 'line' & returns the size of the line
 * Returns -1 if EOF is encountered
 */
int getl(char line[], int size)
{
	int i = 0;
	int c;

	for(i=0; i<size-1 && (c=getchar())!=EOF && c!='\n'; ++i)
		line[i] = c;

	if (c == EOF)
		return -1;

	line[i] = '\0';
	return i;
}

/*
 * Copies 'from' to 'to'
 */
void copy(char from[], char to[])
{
	int i = 0;

	while((to[i] = from[i]) != '\0')
		++i;
}

int main()
{
	int len = 0, max_len = 0;
	char line[STR_SIZE], longest_line[STR_SIZE];

	while((len = getl(line, STR_SIZE)) >= 0)
	{
		if (len > max_len)
		{
			max_len = len;
			copy(line, longest_line);
		}
	}
	printf("\n\nLongest = %s\n", longest_line);

	return 0;
}
