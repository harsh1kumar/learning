/*
 * Bubble sort
 */

#include "arr_lib.h"

void bubble_sort(int arr[], const unsigned int& size)
{
	for(unsigned int i = size-1; i>0; --i)
	{
		print_arr(arr, size);
		for(unsigned int j=0; j<i; ++j)
		{
			if (arr[j] > arr[j+1])
				swap(arr[j], arr[j+1]);
		}
	}
}

int main()
{
	int arr[] = {6,5,3,1,8,7,2,4};
	bubble_sort(arr, sizeof(arr)/sizeof(int));
	print_arr(arr, sizeof(arr)/sizeof(int));
	return 0;
}
 
 
