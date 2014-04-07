#include <stdio.h>

/*
 * Reverses the characters of each line in the input
 */

#define MAX_LEN 100

void reverse(char str[], int len)
{
	char temp;
	int i;
	for(i=0; i<len/2; ++i)
	{
		temp = str[len-1-i];
		str[len-1-i] = str[i];
		str[i] = temp;
	}
}

int main()
{
	int c;
	char str[MAX_LEN];

	int i=0;
	while ((c=getchar()) != EOF)
	{
		if (c != '\n')
		{
			str[i++] = c;
		}
		else
		{
			if (i)
			{
				str[i] = '\0';
				reverse(str, i);
				printf("%s\n", str);
			}
			i=0;
		}
	}
	return 0;
}

