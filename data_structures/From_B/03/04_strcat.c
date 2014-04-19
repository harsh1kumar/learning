/*
 * strcat
 */

#include <stdio.h>

char * mystrcat(char * dest, char * src)
{
	char * cated = dest ;
	while(*dest)
		++dest;

	while(*src)
		*(dest++) = *(src++);

	*dest = '\0';

	return (dest = cated);
}

int main()
{
	char dest[100] = "MARK";
	char src[] = "TWAIN";

	printf("%s\n", mystrcat(dest, src));

	dest[4] = '\0';
	printf("%s\n", mystrcat( mystrcat(dest, " "), src));

	return 0;
}

