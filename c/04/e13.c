/*
 * reverse(s): recursively reverse string s
 */

#include <stdio.h>
#include <string.h>

void reverse(char *s, int size);

int main()
{
	char s[10] = "Hello";

	reverse(s, strlen(s));
	printf("%s\n", s);

	strcpy(s ,"Barted");
	reverse(s, strlen(s));
	printf("%s\n", s);

	return 0;
}

void reverse(char *s, int size)
{
	if (size <= 1)
		return;

	char t = s[0];
	s[0] = s[size-1];
	s[size-1] = t;

	reverse(s+1, size-2);
}