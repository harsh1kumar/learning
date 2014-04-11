/*
 * my_strcat(s, t): concatenate strings s & t; pointer version
 */

#include <stdio.h>

void my_strcat(char * s, char * t);

int main()
{
	char s[] = "Hello", t[] = " World";

	my_strcat(s, t);
	printf("%s\n", s);

	return 0;
}

void my_strcat(char * s, char * t)
{
	/* Reach 1 beyond \0 */
	while(*s++)
		;

	s--; /* Getting  back to \0*/

	while(*s++ = *t++)
		;
}
