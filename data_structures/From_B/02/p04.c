/*
 * Siever method of finding prime numbers
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int * get_array(int * arr, int max_n);
void set_prime(int * arr, int max_n);

int main()
{
	int max_n;
	int * arr = {0};

	printf("Enter n till which all prime numbers will be listed: ");
	if (scanf("%d", &max_n) != 1)
	{
		fprintf(stderr, "\tError: Incorrect input.\n");
		return 1;
	}

	arr = get_array(arr, max_n);
	if ( arr == NULL )
		return 1;

	set_prime(arr, max_n);

	int i;
	printf("\n\nPrime Numbers = ");
	for (i=0; i < max_n-1; ++i)
		if (arr[i] != 1)
			printf("%02d ", arr[i]);
	printf("\n");

	return 0;
}

int * get_array(int * arr, int max_n)
{
	/* 1 is subtracted as arr will start storing numbers from 2 and not 1 */
	arr = (int *)malloc(sizeof(int) * (max_n-1));
	if (arr == NULL)
	{
		fprintf(stderr, "Error: Memory allocation failed\n");
		return NULL;
	}

	--max_n;
	while(--max_n >= 0)
		arr[max_n] = max_n+2;

	return arr;
}

void set_prime(int * arr, int max_n)
{
	int i;
	int j;

	for (i=2; i <= sqrt(max_n); ++i)
	{
		if (arr[i-2] != 1)
			for (j=2*i; j <= max_n; j += i)
				arr[j-2] = 1;
	}
}


