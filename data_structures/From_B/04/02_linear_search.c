/*
 * Linear search in an int array
 */

#include <stdio.h>

static int linear_search(int * arr, size_t size, int a);

int main()
{
	int a;
	int arr[] = {22, 65, 1, 99, 32, 17, 74, 49, 33, 2};

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
		printf("Index of %d is: %d\n", a, linear_search(arr, (sizeof arr)/(sizeof arr[0]), a));
	}

	return 0;
}

static int linear_search(int * arr, size_t size, int a)
{
	/* Size serves as the array index */
	while(size--)
		if ( arr[size] == a)
			return (int)size;

	return -1;
}
