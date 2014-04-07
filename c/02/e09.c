/*
 * bit count
 */

#include <stdio.h>

int bit_count(int x)
{
	int count = 0;

	while(x!=0)
	{
		x &= (x-1);
		++count;
	}

	return count;
}

int main()
{
	printf("3 bitcount = %d\n", bit_count(3));
	printf("7 bitcount = %d\n", bit_count(7));
	printf("13 bitcount = %d\n", bit_count(13));
	printf("63 bitcount = %d\n", bit_count(63));

	return 0;
}
