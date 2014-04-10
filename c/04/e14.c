/*
 * swap(t, x, y): macro to swap 2 arguments of type t
 */

#include <stdio.h>

#define swap(t,x,y) 	t temp;\
			temp = (x);\
			(x) = (y);\
			(y) = temp;

int main()
{
	int i = 1, j = 2;

	printf("i = %d, j = %d\n", i, j);
	swap(int, i, j);
	printf("i = %d, j = %d\n", i, j);

	return 0;
}
