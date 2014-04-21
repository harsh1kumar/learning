/*
 * Evaluate a polynomial using Horner's method
 */

#include <stdio.h>
#include <stdlib.h>

static int poly_eval(int * poly, int size, int x);

#define POLY_DEGREE 4 /* Max power in the polynomial expression */

int main()
{
	int i;
	char sign = '\0';
	int poly[POLY_DEGREE + 1] = {-9, 8, 7, -6, 5};

	for (i = POLY_DEGREE; i>0; --i)
	{
		printf("%c %dx%d ", sign, abs(poly[i]), i);
		sign = (poly[i-1] >= 0 ? '+' : '-');
	}
	printf("%c %d (for x = 10): ", sign, abs(poly[0]));
	printf("%d\n", poly_eval(poly, POLY_DEGREE+1, 10));

	return 0;
}

static int poly_eval(int * poly, int size, int x)
{
	int result;
	int i;

	result = 0;
	for (i=size-1; i>=0; --i)
	{
		result *= x;
		result += poly[i];
	}

	return result;
}
