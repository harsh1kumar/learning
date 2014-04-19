/*
 * strlen
 */

#include <stdio.h>

static int mystrlen(char * s)
{
	int len = 0;
	while (*(s++))
		++len;
	return len;
}

int main()
{
	printf("%d\n", mystrlen("Hello"));
	printf("%d\n", mystrlen("WTH"));
	printf("%d\n", mystrlen("This is a string"));
	return 0;
}
