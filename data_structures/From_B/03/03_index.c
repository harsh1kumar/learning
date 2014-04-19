/*
 * index(s, pattern): Retuns the first index of s which matches the pattern
 */

#include <stdio.h>
#include <string.h>

/* Minimal error checking used */
static int myindex(char * s, char * pat)
{
	int i, j;
	int pat_len = strlen(pat);

	for (i=0; i <= strlen(s) - pat_len; ++i)
	{
		for (j=0; j<pat_len; ++j)
			if (s[i+j] != pat[j])
				break;

		if (j == pat_len)
			return i;
	}

	return -1;
}

int main()
{
	char s[] = "HIS FATHER IS THE PROFESSOR";
	char pat1[] = "THE";
	char pat2[] = "THEN";
	char pat3[] = " THE ";

	printf("Index of %s in %s is: %d\n", s, pat1, myindex(s, pat1));
	printf("Index of %s in %s is: %d\n", s, pat2, myindex(s, pat2));
	printf("Index of %s in %s is: %d\n", s, pat3, myindex(s, pat3));

	return 0;
}



