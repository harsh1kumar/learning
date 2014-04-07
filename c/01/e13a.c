#include <stdio.h>

/*
 * Prints a 'horizontal' histogram of the lengths of words in the input
 */

#define IN 1
#define OUT 0

void print_histogram(int len)
{
	/* Print histogram */
	putchar('\t');
	for(; len; --len)
		putchar('|');
	putchar('\n');
}

int main()
{
	int c;
	int state = OUT;
	int len = 0;

	while((c=getchar()) != EOF)
	{
		if (c == ' ' || c == '\t' || c == '\n')
		{
			if (state == IN)
			{
				print_histogram(len);
				len = 0;
				state = OUT;
			}
		}
		else
		{
			putchar(c);
			++len;
			state = IN;
		}
	}

	return 0;
}