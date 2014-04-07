/*
 * rightrot(x,n): Return value of x rotated to right by n bit positions
 */

#include <stdio.h>
#include "print_binary.h"

int rightrot(unsigned int x, int n)
{
	int bit_len = sizeof(x)*8;
	int last_bit;

	for(; n!=0; --n)
	{
		last_bit = x&1;
		x = (x>>1) | (last_bit<<(bit_len-1));
	}
	return x;
}

int main()
{
	print_binary(63);
	printf("\n");
	print_binary(rightrot(63, 2));
	printf("\n");

	printf("\n");
	print_binary(245);
	printf("\n");
	print_binary(rightrot(245, 4));
	printf("\n");

	return 0;
}

