#include <stdio.h>

/*
 * Remove trailing space & tabs in input. Remove empty lines.
 */

#define MAX_STORAGE 100

int main()
{
	int c;
	char storage[MAX_STORAGE];

	int i=0;
	while((c=getchar()) != EOF)
	{
		if (c != '\n')
			storage[i++] = c;
		else
		{
			int j;
			for (j=i-1; j>=0; --j)
			{
				if (storage[j] != ' ' && storage[j] != '\t')
				{
					/* This is the position of the last character which is not space or tab */
					storage[j+1] = '\0';
					break;
				}
			}
			storage[i] = '\0';
			if (i != 0)
				printf("%s\n", storage);
			i = 0;
		}
	}

	return 0;
}

