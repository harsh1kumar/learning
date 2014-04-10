/*
 * strrindex(s,t): Returns position of the rightmost occurence of t in s or -1 if there is none
 */

#include <stdio.h>

int strrindex(char s[], char t[])
{
	int pos = -1;
	int i, j, k;

	for(i=0; s[i]!='\0'; ++i)
	{
		for(j=i, k=0; s[j]!='\0' && t[k]!='\0' && s[j]==t[k]; ++j, ++k)
			;

		if (k>0 && t[k] == '\0')
			pos = i;
	}

	return pos;
}

int main()
{
	printf("%d\n", strrindex("abcdefabcdefabcdef", "bcd"));
	printf("%d\n", strrindex("abcdefabcdefabcdef", "xyz"));
	printf("%d\n", strrindex("abcdefabcdefabcdef", "abc"));
	printf("%d\n", strrindex("abcdefabcdefabcdef", "def"));
	printf("%d\n", strrindex("abcdefabcdefabcdef", "e"));
	printf("%d\n", strrindex("abcdefabcdefabcdef", "f"));
	printf("%d\n", strrindex("abcdefabcdefabcdef", "x"));
	printf("%d\n", strrindex("abcdefabcdefabcdef", "bcdef"));
	
	return 0;
}

