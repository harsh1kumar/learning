#include "02_selection_sort.h"

static void swap(int * a, int * b);

void selection_sort(int * arr, int size)
{
	int i, j;
	int min_index;

	for (i=0; i<size; ++i)
	{
		min_index = i;
		for (j=i+1; j<size; ++j)
		{
			if (arr[j] < arr[min_index])
			{
				min_index = j;
			}
		}
		swap(&arr[i], &arr[min_index]);
	}
}

static void swap(int * a, int * b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}


