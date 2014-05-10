#include "05_radix_sort.h"


void radix_sort(int * arr, int size, int digits, int base)
{
	int position[base][size]; /* Main drawback of radix_sort, extra space of O(n) required */
	int pos_len[base]; /* Number of elements entered in each row of position */
	int i;
	int j;
	int k;
	int temp;
	int divider = 1;

	for (i=0; i<base; ++i)
	{
		pos_len[i] = 0;
	}

	for (i=0; i<digits; ++i)
	{
		for (j=0; j<size; ++j)
		{
			temp = ( arr[j]/divider ) % 10;

			/* Insert at index temp, pos_len[temp] */
			position[temp][pos_len[temp]++] = arr[j];
		}

		/* Collect data from position & put in arr */
		temp = 0;
		for (j=0; j<base; ++j)
		{
			for (k=0; k<pos_len[j]; ++k)
			{
				arr[temp++] = position[j][k];
			}
			pos_len[j] = 0;
		}

		divider *= 10;
	}
}


