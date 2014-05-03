#include "08_heap_sort.h"

#include <stdio.h>

int main()
{
	int heap[] = {6, 4, 2, 5, 2, 1, 3, 5};
	int i;

	for (i=0; i < (sizeof heap)/(sizeof heap[0]); ++i)
		printf("%d ", heap[i]);
	printf("\n");

	heap_sort( heap, (sizeof heap)/(sizeof heap[0]) );

	for (i=0; i < (sizeof heap)/(sizeof heap[0]); ++i)
		printf("%d ", heap[i]);
	printf("\n");

	return 0;
}

