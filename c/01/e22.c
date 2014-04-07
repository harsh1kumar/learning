#include <stdio.h>
#include <stdlib.h>

/*
 * Word Wrap
 */

#define WRAP_WIDTH 80
#define MAX_WORD_LEN (WRAP_WIDTH+1)

int main()
{
	int c;
	char word[MAX_WORD_LEN];
	unsigned int word_idx = 0;
	unsigned int width = 0;

	FILE * fp;
	fp = fopen ("log.txt", "w");
	while((c=getchar()) != EOF)
	{
		if (c == ' ')
		{
			word[word_idx] = '\0';
			word_idx = 0;
			printf("%s", word);
			if (width < WRAP_WIDTH)
			{
				++width;
				printf(" ");
			}
			else if (width == WRAP_WIDTH)
			{
				printf("\n");
				width = 0;
			}
			else
			{
				printf("ERROR: Width > Wrap Width\n");
				return 1;
			}
		}
		else if (c == '\n')
		{
			word[word_idx] = '\0';
			printf("%s\n", word);
			word_idx = 0;
			width = 0;
		}
		else
		{
			/* If word length is longer than wrap width, print a part of the word */
			if (word_idx == WRAP_WIDTH)
			{
				word[word_idx] = '\0';
				printf("%s\n", word);
				word_idx = 0;
				width = 0;
			}

			if (width < WRAP_WIDTH)
			{
				word[word_idx++] = c;
				++width;
			}
			else if (width == WRAP_WIDTH)
			{
				/* New line wraps */
				printf("\n");

				word[word_idx++] = c;
				width = word_idx;
			}
			else
			{
				printf("ERROR: Width > Wrap Width\n");
				return 1;
			}
		}
		fprintf(fp, "%c %d %d\n", c, width, word_idx);
	}
	fclose(fp);
	printf(":)\n");
	return 0;
}
