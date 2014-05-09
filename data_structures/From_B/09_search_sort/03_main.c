#include <stdio.h>

#include "03_merge_sort.h"

int main()
{
	int i;
	int arr[] = {66, 33, 40, 22, 55, 88, 60, 11, 80, 20, 50, 44, 77, 30, 10};

	for (i=0; i<(sizeof arr/sizeof arr[0]); ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	merge_sort(arr, sizeof arr/sizeof arr[0]);

	for (i=0; i<(sizeof arr/sizeof arr[0]); ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}

