/*
 * Quick Sort
 */

#include <stdio.h>

void swap(int * a, int * b);
void qsort(int arr[], int left, int right);

int main()
{
	int arr[] = {10, 8, 11, 2, 5, 1, 12, 7, 3};
	int i;

	qsort(arr, 0,  (sizeof(arr)/sizeof(int))-1);

	for (i=0; i< sizeof(arr)/sizeof(int); ++i)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}

void qsort(int arr[], int left, int right)
{
	int i, last;

	if (left >= right )
		return;
	swap(&arr[left], &arr[(left+right)/2]);

	last = left;
	for(i=left+1; i<=right; ++i)
		if (arr[left] > arr[i])
			swap(&arr[++last], &arr[i]);

	swap(&arr[left], &arr[last]);
	qsort(arr, left, last-1);
	qsort(arr, last+1, right);
}

void swap(int * a, int * b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
