/*
 * substring(s, i, len) : returns a pointer to substring starting at index i & of length len
 */

#include <stdio.h>
#include <string.h>

#define SUBSTRING_LEN 20

static void substring(char * s, char * subs, int i, int len)
{
	if (len >= SUBSTRING_LEN)
	{
		fprintf(stderr, "Length of substring requested exceeds max substring size. "
				"Generating substing of maximum substring size.\n");
		len = SUBSTRING_LEN-1;
	}

	if (i >= strlen(s))
	{
		fprintf(stderr, "Index i greater than valid index for string s. "
				"Generated an empty substring.\n");
		*subs = '\0';
		return;
	}

	if (len+i > strlen(s))
	{
		fprintf(stderr, "len is too long and/or index is too high to generate a valid substing. "
				"Generating the longest substring possible with the given index.\n");
		len = strlen(s)-i;
	}

	subs[len] = '\0';
	while(--len >= 0)
		subs[len] = s[i+len];
}

int main()
{
	char s1[] = "TO BE OR NOT TO BE";
	char s2[] = "THE END";
	char subs[SUBSTRING_LEN];

	substring(s1, subs, 3, 7);
	printf("\nSubstring 1: %s\n", subs);

	substring(s2, subs, 3, 4);
	printf("\nSubstring 2: %s\n", subs);

	return 0;
}

