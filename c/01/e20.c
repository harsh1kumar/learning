#include <stdio.h>

/*
 * Replace tab with spaces
 */

#define TAB_LEN 8

void detab()
{
	int c;
	int column=0;

	while((c=getchar()) != EOF)
	{
		if (c == '\t')
		{
			/* Insert spaces */
			int spaces;
			if (!(spaces =  TAB_LEN - (column % TAB_LEN)))
				spaces = TAB_LEN;

			fprintf(stderr, "%d %d\n", spaces, column);
			column += spaces; /* Increment column with the number of spaces added. */
			for ( ; spaces > 0; --spaces)
				putchar(' ');
		}
		else if (c == '\n')
		{
			putchar(c);
			column = 0;
		}
		else
		{
			putchar(c);
			++column;
		}
	}
}

int main()
{
	detab();
	return 0;
}

