/*
 * Algo1 for pattern matching: 	Seach pattern in string one character at a time
 * 				moving from left to right in the string.
 */

#include <stdio.h>
#include <string.h>

int myindex(char *s, char * pat);

int main()
{
	printf("%d\n", myindex("aabbbabb", "bab"));
	return 0;
}

/* Minimal error checking in this code. User must use his head & not do anything stupid */
int myindex(char *s, char * pat)
{
	int i, j;
	int pat_len = strlen(pat);

	for (i=0; i <= strlen(s)-pat_len; ++i)
	{
		for (j=0; j < pat_len; ++j)
			if (s[i+j] != pat[j])
				break;

		if (j == pat_len)
			return i;
	}

	return -1;
}
