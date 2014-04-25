#include <stdio.h> 

#include "06_quick_sort.h"

int main()
{
	int arr[] = {44, 33, 11, 55, 77, 90, 40, 60, 99, 22, 88, 66};
	int i;

	for (i=0; i<(sizeof arr)/(sizeof arr[0]); ++i)
		printf("%d ", arr[i]);
	printf("\n");

	quick_sort(arr, 0, (sizeof arr)/(sizeof arr[0])-1);
	for (i=0; i<(sizeof arr)/(sizeof arr[0]); ++i)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}
