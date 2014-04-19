/*
 * Prints number of digits & sum of digits in an integer
 */

#include <stdio.h>

int main()
{
	int n;
	int sum;
	int digits;

	printf("Enter an integer: ");
	if (scanf("%d", &n) != 1)
	{
		fprintf(stderr, "Incorrect input\n");
		return 1;
	}

	for(sum = (n%10), digits=1; (n /= 10) != 0; ++digits, sum += (n%10))
		;

	printf("Sum = %d, Digits = %d\n", sum, digits);

	return 0;
}
