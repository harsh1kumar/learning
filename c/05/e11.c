#include <stdio.h>

/*
 * Replace tab with spaces
 */

#define TAB_LEN 8

void detab(char *tab[], int size)
{
	int c;
	int column=0;
	int i;

	while((c=getchar()) != EOF)
	{
		for (i=0; i < size; ++i)
		{
			if (c == tab[i][0])
			{
				/* Insert spaces */
				int spaces;
				if (!(spaces =  TAB_LEN - (column % TAB_LEN)))
					spaces = TAB_LEN;

				column += spaces; /* Increment column with the number of spaces added. */
				for ( ; spaces > 0; --spaces)
					putchar(' ');
				break;
			}
		}
		if (i<size)
			continue;

		if (c == '\n')
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

#define MAX_TAB_STOPS 10

int main(int argc, char *argv[])
{
	char ** tabs;

	*tabs = "t"; // Default tab

	if (argc==1)
		detab(tabs, 1);
	else
		detab(++argv, --argc);

	return 0;
}

