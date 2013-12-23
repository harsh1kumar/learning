/*
 * Selection sort
 */

#include "arr_lib.h"

void selection_sort(int arr[], const unsigned int& size)
{
	int min;
	for(unsigned int i=0; i<size; ++i)
	{
		print_arr(arr, size);
		min = i;
		for(unsigned int j=i+1; j<size; ++j)
		{
			if (arr[j] < arr[min])
				min = j;
		}
		swap(arr[i], arr[min]);
	}
}

int main()
{
	int arr[] = {6,5,3,1,8,7,2,4};
	selection_sort(arr, sizeof(arr)/sizeof(int));
	print_arr(arr, sizeof(arr)/sizeof(int));
	return 0;
}
 
