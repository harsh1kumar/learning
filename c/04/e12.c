/*
 * itoa(n, s): recursively get characters of n into string s
 */

#include <stdio.h>

int itoa(int n, char * s);

int main()
{
	char s[10];
	
	itoa(1224, s);
	printf("%s\n", s);
	itoa(-1224, s);
	printf("%s\n", s);

	return 0;
}

int itoa(int n, char * s)
{
	int i;
	if (n < 0)
	{
		s[0] = '-';
		i = 1;
	}
	else
		i=0;

	if (n/10)
		i = itoa(n/10, s);

	s[i++] = (abs(n)%10 + '0');
	s[i] = '\0';
	return i;
}

 
