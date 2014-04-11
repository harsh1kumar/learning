/*
 * strncpy, strncat, strncmp
 */

#include <stdio.h>

char * my_strncpy(char *d, char *s, int n);
char * my_strncat(char *d, char *s, int n);
int my_strncmp(char *s1, char *s2, int n);

int main()
{
	char d[] = "Hello World";
	char s[] = "How are u";

	printf("%s\n", my_strncpy(d, s, 5));
	printf("%s\n", my_strncpy(d, s, 20));
	printf("%s\n", my_strncpy(d, s, 1));
	printf("%s\n", my_strncpy(d, s, 0));

	my_strncpy(d, "Hello World", 20);
	printf("%s\n", my_strncat(d, s, 5));
	my_strncpy(d, "Hello World", 20);
	printf("%s\n", my_strncat(d, s, 12));
	my_strncpy(d, "Hello World", 20);
	printf("%s\n", my_strncat(d, s, 1));
	my_strncpy(d, "Hello World", 20);
	printf("%s\n", my_strncat(d, s, 0));

	my_strncpy(d, "Hello World", 20);
	printf("%d\n", my_strncmp(d, s, 1));
	printf("%d\n", my_strncmp(d, s, 2));
	printf("%d\n", my_strncmp(d, s, 3));

	return 0;
}

char * my_strncpy(char *d, char *s, int n)
{
	char *d_start = d;

	while (n--)
		if ((*d++ = *s++) == '\0')
			break;

	*d = '\0';

	return d_start;
}

char * my_strncat(char *d, char *s, int n)
{
	char *d_start = d;

	while(*d++)
		;
	d--;

	while (n--)
		if ((*d++ = *s++) == '\0')
			break;

	*d = '\0';

	return d_start;
}

int my_strncmp(char *s1, char *s2, int n)
{
	while (n-- && (*s1++ == *s2++))
		if (*s1 == '\0')
			return 0;
	if (!n)
		return 0;

	return (*--s1) - (*--s2);
}


