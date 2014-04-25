/*
 * Factorial
 */

#include <stdio.h>

static int factorial_recur(int n);
static int factorial(int n);

int main()
{
	int i = 7;

	printf("Factorial of %d is: %d (Recursion)\n", i, factorial_recur(i));
	printf("Factorial of %d is: %d\n", i, factorial(i));

	return 0;
}

static int factorial_recur(int n)
{
	if (n == 1)
		return 1;

	return n * factorial_recur(n-1);
}

static int factorial(int n)
{
	int retval = 1;

	while (n != 1)
		retval *= n--;

	return retval;
}