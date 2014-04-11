/*
 * my_strend(s, t): returns 1 if string t occurs at the end of sting s, 0 otherwise
 */

#include <stdio.h>
#include <string.h>

int my_strend(char * s, char * t);

int main()
{
	printf("%d\n", my_strend("Hello World", "rld"));
	printf("%d\n", my_strend("Hello World", "World"));
	printf("%d\n", my_strend("Hello World", " World"));
	printf("%d\n", my_strend("Hello World", "Wrld"));
	printf("%d\n", my_strend("Hello World", "Wor"));
	printf("%d\n", my_strend("Hello World", "Hello World"));

	return 0;
}

int my_strend(char * s, char * t)
{
	int s_len = strlen(s);
	int t_len = strlen(t);

	s += (s_len - t_len); /* This is the position where at the end of s where t may be starting */

	while(*s++ == *t++)
		if (!*s) // Reached '\0'
			return 1;

	return 0;
}
