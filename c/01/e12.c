#include <stdio.h>

/*
 * Print input as one word per line
 */

#define IN 1
#define OUT 0

int main()
{
	int c;
	int state = OUT;

	while ((c=getchar()) != EOF)
	{
		if (c == ' ' || c == '\n' || c == '\t')
		{
			if (state == IN)
			{
				putchar('\n');
				state = OUT;
			}
		}
		else
		{
			putchar(c);
			state = IN;
		}
	}

	return 0;
}
