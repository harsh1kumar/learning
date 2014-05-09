#include "03_merge_sort.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void merge(int * arr3, int * arr1, int size1, int * arr2, int size2);
static void merge_pass(int * arr2, int * arr1, int size, int mergelen);

void merge_sort(int * arr, int size)
{
	int i;
	int * temp_arr = NULL;

	temp_arr = malloc(size * sizeof(int));
	if (temp_arr == NULL)
	{
		fprintf(stderr, "Error: Memory allocation failed\n");
		exit(1);
	}

	i=1;
	for (i=1; i<size; i *= 4)
	{
		merge_pass(temp_arr, arr, size, i);
		merge_pass(arr, temp_arr, size, i*2);
	}

	free(temp_arr);
}

/*
 * Merge 2 arrays arr1 & arr2 with size size1 & size2 respectively.
 * Merged array is stored in arr3
 */
static void merge(int * arr3, int * arr1, int size1, int * arr2, int size2)
{
	int i, j, k;

	for (k=0, i=0, j=0; i<size1 && j<size2; ++k)
	{
		if ( arr1[i] < arr2[j])
		{
			arr3[k] = arr1[i++];
		}
		else if (arr1[i] > arr2[j])
		{
			arr3[k] = arr2[j++];
		}
		else
		{
			arr3[k] = arr1[i++];
			++j;
		}
	}

	for ( ; i<size1; ++k)
	{
		arr3[k] = arr1[i++];
	}

	for ( ; j<size2; ++k)
	{
		arr3[k] = arr2[j++];
	}
}

/* Merge 2 consecutive sub-arrys of arr1 each of length mergelen & store in arr2 */
static void merge_pass(int * arr2, int * arr1, int size, int mergelen)
{
	int i;

	for (i=0; i <= (size - (2*mergelen)); i += (2*mergelen))
	{
		merge(&arr2[i], &arr1[i], mergelen, &arr1[i+mergelen], mergelen);
	}

	if (size-i>mergelen)
	{
		merge(&arr2[i], &arr1[i], mergelen, &arr1[i+mergelen], size-i-mergelen);
	}
	else
	{
		memcpy(&arr2[i], &arr1[i], (size-i)*(sizeof arr1[0]));
	}
}

