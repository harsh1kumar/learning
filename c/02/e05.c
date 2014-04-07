/*
 * any(s1, s2): Returns first location of any character of s2 that appears in s1.
 * 		Return -1 if there are no characters of s2 in s1.
 */

#include <stdio.h>
#include <string.h>

int any(char s1[], char s2[])
{
	unsigned int index = ~0;
	int i, j;
	for (i=0; s2[i] != '\0'; ++i)
	{
		for (j=0; s1[j] != '\0'; ++j)
		{
			if (s1[j] == s2[i])
				index = (index > j) ? j: index;
		}
	}
	return (index != ~0 ? index+1 : -1);
}

int main()
{
	char s1[] = "abcdefgh-abcdefgh-abcdefgh";
	char s2[] = "hce";
	char s3[] = "-ty";
	char s4[] = "xyz";

	printf("%d\n", any(s1, s2));
	printf("%d\n", any(s1, s3));
	printf("%d\n", any(s1, s4));

	return 0;
}
 
