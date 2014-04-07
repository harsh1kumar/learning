/*
 * htoi(s): convert hex to integer
 */

#include <stdio.h>

#define HEX_BASE 16
#define A_IN_DECIMAL 10

int htoi(char hex[])
{
	int integer = 0;
	int i=0;

	if (hex[0] == '0' && hex[1] == 'x')
		i = 2;

	while(hex[i] != '\0')
	{
		if (isdigit(hex[i]))
			integer = (integer * HEX_BASE) + hex[i] -'0';
		else
			integer = (integer * HEX_BASE) + hex[i] - 'A' + A_IN_DECIMAL;
		++i;
	}
	return integer;
}

int main()
{
	printf("0x%X : %d\n", 0xA, htoi("0xA"));
	printf("0x%X : %d\n", 0xA, htoi("A"));
	printf("0x%X : %d\n", 0x1A, htoi("0x1A"));
	printf("0x%X : %d\n", 0x6FA, htoi("6FA"));

	return 0;
}
