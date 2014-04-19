/*
 * Find the largest & second largest number in array.
 * 
 * NOTE: Not finding the location but the numbers.
 */

#include <stdio.h>
#include <stdlib.h>

static void find(int * arr, int size, int * lp, int *slp);

int main()
{
	int arr[] = { 70, 30, 25, 80, 60, 50, 30, 75, 25, 60};
	int largest = 0;
	int sec_largest = 0;

	find(arr, (int)((sizeof arr)/(sizeof arr[0])), &largest, &sec_largest);

	printf("Largest = %d\nSecond Largest = %d\n\n", largest, sec_largest);

	return 0;
}

static void find(int * arr, int size, int * lp, int *slp)
{
	int * ap = arr;

	if (size < 2)
	{
		fprintf(stderr, "Error: Array is too small\n");
		exit(EXIT_FAILURE);
	}

	if (*ap > *(ap+1))
	{
		*lp = *(ap++);
		*slp = *(ap++);
	}

	while( ap < (arr+size) )
	{
		if (*ap > *lp)
		{
			*slp = *lp;
			*lp = *ap;
		}
		else if (*ap > *slp)
			*slp = *ap;

		++ap;
	}
}


