/*
 * squeese(s1, s2): delete each character in s1 that matches any character in s2
 */

#include <stdio.h>

void squeese(char s1[], char s2[])
{
	int i, j, k;
	for (i=0; s2[i] != '\0'; ++i)
	{
		for (j=k=0; s1[j] != '\0'; ++j)
		{
			if (s1[j] != s2[i])
				s1[k++] = s1[j];
		}
		s1[k] = '\0';
	}
}

int main()
{
	char s1[] = "abcdefgh-abcdefgh-abcdefgh";
	char s2[] = "hce";
	char s3[] = "dag";

	squeese(s1, s2);
	printf("%s\n", s1);

	squeese(s1, s3);
	printf("%s\n", s1);

	return 0;
}
