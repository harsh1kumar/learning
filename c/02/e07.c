/*
 * invert(x,p,n): Return x with n bits that begin at position p inverted
 */

#include <stdio.h>
#include "print_binary.h"

int invert(int x, int p, int n)
{
	return x ^ ((~(~0 << n)) << p-n+1);
}

int main()
{
	print_binary(255);
	printf(" : 255\n");
	print_binary(invert(255, 5, 2));
	printf(": invert(255, 5, 2)\n");

	print_binary(57);
	printf(" : 57\n");
	print_binary(invert(57, 3, 3));
	printf(": invert(57, 3, 3)\n");

	return 0;
}

