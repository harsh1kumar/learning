#include "04_shell_sort.h"

#include <stdio.h>

static void modified_insert_sort(int * arr, int size, int jump);

void shell_sort(int * arr, int size)
{
	int i;
	int j;

	for (i=size/2; i>0; i /= 2)
	{
		for (j=0; j<i; ++j)
		{
			modified_insert_sort(&arr[j], size-j, i);
		}
	}
}

/* Insertion sort where array elements start at arr & occur at every 'jump'th index */
static void modified_insert_sort(int * arr, int size, int jump)
{
	int temp;
	int i;
	int j;

	for (i=jump; i<size; i += jump)
	{
		temp = arr[i];
		for (j=i-jump; j>=0; j -= jump)
		{
			if (arr[j] > temp)
			{
				arr[j+jump] = arr[j];
			}
			else
			{
				break;
			}
		}
		arr[j+jump] = temp;
	}
}





