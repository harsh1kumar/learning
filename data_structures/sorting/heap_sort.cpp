/*
 * Heap sort
 */

#include "arr_lib.h"

/* Make a heap */
void heapify(int heap[], const unsigned int& node)
{
	int parent;
	int child = node;
	while (child!=0 && ((parent = (child-1)/2) >= 0))
	{
		if (heap[parent] < heap[child])
			swap(heap[parent], heap[child]);
		child = parent;
	}
}

void heap_sort(int arr[], const unsigned int& size)
{
	int heap[size];

	// Copy array to heap
	for(unsigned int i=0; i<size; ++i)
		heap[i] = arr[i];

	for(unsigned int i=size; i>0; --i)
	{
		for(unsigned int j=0; j<i; ++j)
		{
			// Make heap
			heapify(heap, j);
		}
		// Max element(at 0) exchanged with last element & then put at end in arr
		swap(heap[0], heap[i-1]);
		arr[i-1] = heap[i-1];
	}
}

int main()
{
	int arr[] = {6,5,3,1,8,7,2,4};
	heap_sort(arr, sizeof(arr)/sizeof(int));
	print_arr(arr, sizeof(arr)/sizeof(int));
	return 0;
}
 
