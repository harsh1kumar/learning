/*
 * Bubble sort
 */

#include <stdio.h>

static void printarr(int * arr, const size_t size);
static void swap(int * a, int * b);
static void bubble_sort(int * arr, const size_t size);

int main()
{
	int arr1[] = {8, 4, 19, 2, 7, 13, 5, 16};
	int arr2[] = {32, 51, 27, 85, 66, 23, 13, 57};

	printarr(arr1, (sizeof arr1)/(sizeof arr1[0]));
	bubble_sort(arr1, (sizeof arr1)/(sizeof arr1[0]));
	printarr(arr1, (sizeof arr1)/(sizeof arr1[0]));

	printf("\n");
	printarr(arr2, (sizeof arr2)/(sizeof arr2[0]));
	bubble_sort(arr2, (sizeof arr2)/(sizeof arr2[0]));
	printarr(arr2, (sizeof arr2)/(sizeof arr2[0]));

	return 0;
}

static void printarr(int * arr, const size_t size)
{
	int i;
	for (i=0; i < (int)size; ++i)
		printf("%2d ", arr[i]);
	printf("\n");
}

static void swap(int * a, int * b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

static void bubble_sort(int * arr, const size_t size)
{
	int i, j;

	for (i = (int)size - 1; i>=1; --i)
		for(j=0; j<i; ++j)
			if ( arr[j] > arr[j+1] )
				swap(&arr[j], &arr[j+1]);
}


