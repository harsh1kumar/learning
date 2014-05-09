#include <stdio.h>

#include "04_shell_sort.h"

int main()
{
	int i;
	int arr[] = {13, 17, 19, 10, 15, 11, 16, 18, 14, 1, 5, 4, 3, 2, 6, 9, 7};

	for (i=0; i<(sizeof arr/sizeof arr[0]); ++i)
	{
		printf("%2d ", arr[i]);
	}
	printf("\n\n");

	shell_sort(arr, (sizeof arr)/(sizeof arr[0]));

	for (i=0; i<(sizeof arr/sizeof arr[0]); ++i)
	{
		printf("%2d ", arr[i]);
	}
	printf("\n");

	return 0;
}


