/*
 * insert(s1, idx, s2): insert s2 in s1 at index idx. s1 must be of sufficient size
 */

#include <stdio.h>
#include <string.h>

static void insert(char * s1, int idx, char * s2)
{
	int s2_len = strlen(s2);
	int i, j;

	/* Shifting later characters */
	memmove(s1 + idx+s2_len, s1+idx, strlen(s1) - idx+1);

	for(i=idx, j=0; j<s2_len; ++i, ++j)
		s1[i] = s2[j];
}

int main()
{
	char s1[100] = "ABCDEFG";

	insert(s1, 2, "XYZ");
	printf("%s\n", s1);

	strcpy(s1, "ABCDEFG");
	insert(s1, 5, "XYZ");
	printf("%s\n", s1);

	return 0;
}

