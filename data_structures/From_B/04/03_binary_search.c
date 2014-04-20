/*
 * Binary search for an array of int
 */

#include <stdio.h>

static int binary_search(int * arr, size_t size, int a);
static int binary_search_recur(int * arr, int start, int end, int a);

int main()
{
	int a;
	int arr[] = {1, 2, 17, 22, 32, 33, 49, 65, 74, 99};

	while(1)
	{
		printf("Enter number to search (-1 to exit): ");
		if ( scanf("%d", &a) != 1)
		{
			fprintf(stderr, "Wrong input.\n\n");
			break;
		}
		if (a == -1)
			break;
		printf("Index of %d is: %d\n", a, binary_search(arr, (sizeof arr)/(sizeof arr[0]), a));
		printf("Index of %d is: %d (by recursion)\n\n", a, binary_search_recur(arr, 0, ((sizeof arr)/(sizeof arr[0])) -1, a));
	}

	return 0;
}

static int binary_search(int * arr, size_t size, int a)
{
	int mid;
	int start = 0;
	int end = size-1;

	for (mid = (start+end)/2; start <= end; mid = (start+end)/2)
	{
		if (arr[mid] == a)
			return mid;
		else if (arr[mid] > a)
			end = mid - 1;
		else
			start = mid + 1;
	}
	return -1;
}

static int binary_search_recur(int * arr, int start, int end, int a)
{
	if (start > end)
		return -1;

	int mid = (start + end)/2;
	if (arr[mid] == a)
		return mid;
	else if (arr[mid] > a)
		return binary_search_recur(arr, start, mid-1, a);
	else
		return binary_search_recur(arr, mid+1, end, a);

}