#include "e03_getop.h"
#include <stdio.h>

/*
 * Returns operators or NUMBER.
 * 	Value of macro NUMBER is returned when a number is to be returned. 
 * 	The number is saved in string s.
 */
int getop(char s[])
{
	int c;
	int i;
	static int eof = 0;

	if (eof)
		return EOF;

	while((s[0] = c = getchar()) != EOF && (c == ' ' || c == '\t'))
		;

	i=1;
	if (!isdigit(c))
	{
		/* It maybe an operator or a sign symbol. Check the next character */
		s[1] = c = getchar();
		if (!isdigit(c))
		{
			/* s[0] was an operator as s[1] is not a digit */
			if (c == EOF)
				eof = 1;
			return s[0];
		}

		/* If here, then s[0] must be a sign symbol as s[1] is a digit.
		 * Incrementing i as 2 characters have been stored.
		 */
		++i;
	}

	while( isdigit(s[i++] = c = getchar()) )
		;

	/* Continue adding digits if c was just a decimal point */
	if (c == '.')
	{
		while( isdigit(s[i++] = c = getchar()) )
		;
	}
	s[i] ='\0';

	if (c == EOF || c == '\n')
		eof = 1;

	return NUMBER;
}
