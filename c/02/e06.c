/*
 * setbits(x,p,n,y): Return x with n bits that begin at position p set to the
 * 		right most n bits of y leaving the other bits unchanged
 */

#include <stdio.h>
#include "print_binary.h"

int setbits(int x, int p, int n, int y)
{
	return ((x >> (p-n+1)) & ~(~0 << n)) | (y & (~0 << n));
}

int main()
{
	print_binary(45);
	printf("\n");
	print_binary(38);
	printf("\n");
	print_binary(setbits(45, 4, 4, 38));
	printf("\n");
	print_binary(setbits(45, 4, 2, 38));
	printf("\n");
	print_binary(setbits(45, 3, 2, 38));
	printf("\n");

	return 0;
}

