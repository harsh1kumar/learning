/*
 * Binary search and insert
 */

#include <stdio.h>
#include <assert.h>

static int search_n_insert(int * arr, int size, int add_it);
static void print_arr(int * arr, int size);

#define ARR_SIZE 10

int main()
{
	int arr[ARR_SIZE] = {10};
	int size = 1;

	print_arr(arr, size);

	printf("Add 20: ");
	size = search_n_insert(arr, size, 20);
	print_arr(arr, size);

	printf("Add 10: ");
	size = search_n_insert(arr, size, 10);
	print_arr(arr, size);

	printf("Add 30: ");
	size = search_n_insert(arr, size, 30);
	print_arr(arr, size);

	printf("Add 15: ");
	size = search_n_insert(arr, size, 15);
	print_arr(arr, size);

	printf("Add  7: ");
	size = search_n_insert(arr, size, 7);
	print_arr(arr, size);

	printf("Add 25: ");
	size = search_n_insert(arr, size, 25);
	print_arr(arr, size);

	printf("Add 50: ");
	size = search_n_insert(arr, size, 50);
	print_arr(arr, size);

	return 0;
}

static int search_n_insert(int * arr, int size, int add_it)
{
	int mid;
	int start = 0;
	int end = size-1;

	for ( mid = (start+end)/2; start < end; mid = (start+end)/2 )
	{
		if ( arr[mid] == add_it )
			return size;
		else if ( arr[mid] > add_it )
			end = mid - 1;
		else
			start = mid + 1;
	}
	assert(start == end && end == mid );

	/* add_it to be inserted */
	int add_index;
	int i;
	if ( arr[mid] > add_it)
		add_index = mid;
	else
		add_index = mid + 1;

	/* Shift items */
	for (i=size-1; i >= add_index; --i)
		arr[i+1] = arr[i];

	/* Add the new item */
	arr[add_index] = add_it;

	return ++size;
}

static void print_arr(int * arr, int size)
{
	int i;

	for (i=0; i<size; ++i)
		printf("%02d ", arr[i]);
	printf("\n");
}