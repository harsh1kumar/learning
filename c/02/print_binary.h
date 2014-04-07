#ifndef PRINT_BINARY_H
#define PRINT_BINARY_H

/*
 * Print binary of an integer - only 8 bit integers will be valid
 */

#include <stdio.h>

void print_binary(unsigned int x)
{
	int bit_len = sizeof(x)*8;

	char bits[bit_len+1];
	int i;
	for(i=0; i< bit_len; ++i)
		bits[i] = '0';
	bits[bit_len] = '\0';

	for(i=bit_len-1 ; i>=0; x >>= 1)
		bits[i--] = (x&1) ? '1': '0';
	printf("%s", bits);
}

#endif
