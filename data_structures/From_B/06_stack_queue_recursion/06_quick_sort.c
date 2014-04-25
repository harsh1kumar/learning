/*
 * Quick Sort
 */

#include "06_quick_sort.h"

#include <stdio.h>
#include <stdlib.h>

static void swap(int * a, int * b);

void quick_sort(int * arr, int start, int end)
{
	int final = start;
	int cmp = end;

	while (final != cmp)
	{
		/* Move left */
		while ( arr[final] <= arr[cmp] && final != cmp )
			--cmp;

		if ( final == cmp )
			break;

		if ( arr[final] > arr[cmp] )
		{
			swap( &arr[final], &arr[cmp] );
			swap( &final, &cmp );
			++cmp;
		}
		
		/* Move Right */
		while ( arr[final] >= arr[cmp] && final != cmp )
			++cmp;

		if ( final == cmp )
			break;

		if ( arr[final] < arr[cmp] )
		{
			swap( &arr[final], &arr[cmp] );
			swap( &final, &cmp );
			--cmp;
		}
	}

	if (final != start)
		quick_sort(arr, start, final-1);

	if (final != end)
		quick_sort(arr, final+1, end);
}

static void swap(int * a, int * b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

