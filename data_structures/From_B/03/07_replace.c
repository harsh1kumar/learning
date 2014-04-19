/*
 * replace(s, pat1, pat2): replace pat1 with pat2 in string s
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

static void replace(char * s, char * pat1, char * pat2)
{
	int i, j;
	int s_len = strlen(s);
	int pat1_len = strlen(pat1);
	int pat2_len = strlen(pat2);

	for (i=0; i <= s_len - pat1_len; ++i)
	{
		for (j=0; j < pat1_len; ++j)
			if (s[i+j] != pat1[j])
				break;
		
		if (j == pat1_len)
		{
			/* Found pat1 */
			memmove(s+i+pat2_len, s+i+pat1_len, s_len-i-pat1_len+1);
			memcpy(s+i, pat2, pat2_len);
			return;
		}
	}
	
}

int main()
{
	char s[20] = "XABYABZ";
	char pat1[20];

	replace(s, "AB", "C");
	printf("%s\n", s);

	strcpy(s, "XABYABZ");
	replace(s, "BA", "C");
	printf("%s\n", s);

	strcpy(s, "XABYABZ");
	replace(s, "BZ", "CBD");
	printf("%s\n", s);


	strcpy(s, "XABYABZ");
	strcpy(pat1, "AB");
	while( myindex(s, pat1) != -1)
		replace(s, pat1, "C");
	printf("%s\n", s);

	return 0;
}

