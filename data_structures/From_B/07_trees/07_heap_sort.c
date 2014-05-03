#include "08_heap_sort.h"


static void add2heap(int heap[], int n, int data);
static int del_root(int heap[], int n);

/* Add data to the heap. heap is a heap with n elements */
static void add2heap(int heap[], int n, int data)
{
	int idx_parent;
	int idx_child;

	idx_child = n; /* Index of nth element */
	while (idx_child > 0)
	{
		idx_parent = (idx_child-1)/2;
		if ( heap[idx_parent] < data)
		{
			heap[idx_child] = heap[idx_parent];
			idx_child = idx_parent;
		}
		else
			break;
	}
	heap[idx_child] = data;
}

/* heap is a heap with n elements 
 * This function will return the deleted root
 */
static int del_root(int heap[], int n)
{
	int retval;
	int idx_parent;
	int idx_left;
	int last_node;

	retval = heap[0];
	--n;
	/* Last element of the heap made the new root at heap[0] */
	last_node = heap[n];

	idx_parent = 0;
	idx_left = 1;
	while (idx_left + 1 <= n-1) /* Right index = idx_left+1 */
	{
		if (heap[idx_left] > last_node || heap[idx_left+1] > last_node)
		{
			if (heap[idx_left] > heap[idx_left+1])
			{
				/* Left child greater, making it the parent */
				heap[idx_parent] = heap[idx_left];
				idx_parent = idx_left;
				
			}
			else
			{
				/* Right child greater, making it the parent */
				heap[idx_parent] = heap[idx_left+1];
				idx_parent = idx_left+1;
			}

			idx_left = 2*idx_parent + 1;
		}
		else
			break;
	}
	heap[idx_parent] = last_node;

	if (idx_left == n-1 && heap[idx_left] > last_node)
	{
		heap[idx_parent] = heap[idx_left];
		heap[idx_left] = last_node;
	}

	return retval;
}

void heap_sort(int heap[], int len)
{
	int i;

	for (i=1; i < len; ++i)
		add2heap(heap, i , heap[i]);

	/* For ascending */
	for (i=0; i < len; ++i)
		heap[len-1-i] = del_root(heap, len-i);

}






