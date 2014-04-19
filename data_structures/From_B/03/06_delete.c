/*
 * delete(s, idx, len): delete the substring of length len at index idx
 */

#include <stdio.h>
#include <string.h>

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

static void delete(char * s, int idx, int len)
{
	if (idx < 0 || idx >= strlen(s))
		return;

	memmove(s+idx, s+idx+len, strlen(s)-idx-len + 1);
}

int main()
{
	char s[10] = "ABCDEFG";
	char pat[10] = "CD";
	int idx;

	delete(s, 3, 2);
	printf("%s\n", s);

	strcpy(s, "ABCDEFG");
	delete(s, 1, 4);
	printf("%s\n", s);

	strcpy(s, "ABCDEFG");
	delete(s, myindex(s, pat), strlen(pat));
	printf("%s\n", s);

	strcpy(s, "ABCDEFG");
	strcpy(pat, "DC");
	delete(s, myindex(s, pat), strlen(pat));
	printf("%s\n", s);

	strcpy(s, "XABYABZ");
	strcpy(pat, "AB");
	while( (idx = myindex(s,pat)) != -1)
		delete(s, idx, strlen(pat));
	printf("%s\n", s);

	strcpy(s, "XAAABBBY");
	while( (idx = myindex(s,pat)) != -1)
		delete(s, idx, strlen(pat));
	printf("%s\n", s);

	return 0;
}

