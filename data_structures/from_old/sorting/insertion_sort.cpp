/*
 * Insertion sort
 */

#include "arr_lib.h"

void insertion_sort(int arr[], const unsigned int& size)
{
	int tmp;
	for(unsigned int i=1; i<size; ++i)
	{
		tmp = arr[i];
		print_arr(arr, size);
		for(unsigned int j=i-1; j>=0; --j)
		{
			if (arr[j] > tmp)
			{
				arr[j+1] = arr[j];
			}
			else
			{
				arr[j+1] = tmp;
				break;
			}
		}
	}
}

int main()
{
	int arr[] = {6,5,3,1,8,7,2,4};
	insertion_sort(arr, sizeof(arr)/sizeof(int));
	print_arr(arr, sizeof(arr)/sizeof(int));
	return 0;
}
