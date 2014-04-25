/*
 * Print Fibonacci Series
 */

#include <stdio.h>

static int fibonacci(int n);

int main()
{
	int i;
	int n;

	n = 11;
	printf("Fibonacci Series with %d terms\n", n);
	for (i=0; i<n; ++i)
		printf("%d ", fibonacci(i));
	printf("\n");

	return 0;
}

static int fibonacci(int n)
{
	if (n == 0 || n == 1)
		return n;

	return fibonacci(n-1) + fibonacci(n-2);
}
