/*
 * my_getfloat(*pn): get next float from input into *pn
 */

#include <stdio.h>
#include <ctype.h>

int my_getfloat(double *pn);

int main()
{
	double f;

	while(my_getfloat(&f) != EOF)
		printf("%f\n", f);

	return 0;
}

int my_getfloat(double *pn)
{
	int c;
	int sign;

	while(isspace(c = getchar()))
		;

	sign = (c == '-') ? -1 : 1;
	if (c == '-' || c == '+')
		c = getchar();

	if (!isdigit(c) && c != '.')
	{
		fprintf(stderr, "Error: + or - not followed by a digit\n");
		return EOF;
	}

	for(*pn = 0; isdigit(c); c = getchar())
		*pn = *pn * 10 + c - '0';

	long power = 1;
	if (c == '.')
	{
		c = getchar();
		for(; isdigit(c); c = getchar())
		{
			*pn = *pn * 10 + c - '0';
			power *= 10;
		}
	}

	if (c != '\n' && c != ' ' && c != '\t' && c != EOF)
	{
		fprintf(stderr, "Error: Wrong input, unexpected character encountered\n");
		return EOF;
	}

	*pn *= sign;
	*pn /= power;

	return c;
	
}