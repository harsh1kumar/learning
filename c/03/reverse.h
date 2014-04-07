#ifndef REVERSE_H
#define REVERSE_H

#include <string.h>

/*
 * Reverse string s
 */
void reverse(char s[])
{
	int i, j;
	char temp;

	for(i=0, j=strlen(s)-1; i<j; ++i, --j)
	{
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}
}

#endif
