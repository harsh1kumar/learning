#include "01_insertion_sort.h"

void insertion_sort(int * arr, int size)
{
	int i, j;
	int temp;

	for (i=1; i<size; ++i)
	{
		temp = arr[i];
		for (j=i-1; j>=0; --j)
		{
			if ( arr[j] > temp)
			{
				arr[j+1] = a[j];
			}
			else
			{
				break;
			}
		}
		a[j+1] = temp;
	}
}



