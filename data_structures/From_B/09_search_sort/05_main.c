#include <stdio.h>

#include "05_radix_sort.h"

int main()
{
	int arr[] = {348, 143, 361, 423, 538, 128, 321, 543, 366};
	int i;

	for (i=0; i<(sizeof arr/sizeof arr[0]); ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	radix_sort(arr, sizeof arr/sizeof arr[0], 3, 10);

	for (i=0; i<(sizeof arr/sizeof arr[0]); ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}


