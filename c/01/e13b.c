#include <stdio.h>

/*
 * Prints a 'vertical' histogram of the lengths of words in the input
 */

#define IN 1
#define OUT 0
#define MAX_WORDS 10

int get_words_data(int len[], int max_arr_size)
{
	int c;
	int state = OUT;
	int word_number = 0;

	while((word_number < max_arr_size) && (c=getchar()) != EOF)
	{
		if (c == ' ' || c == '\t' || c == '\n')
		{
			if (state == IN)
			{
				++word_number;
				state = OUT;
			}
		}
		else
		{
			++len[word_number];
			state = IN;
		}
	}
	return word_number;
}

int get_max(int arr[], int size)
{
	int i;
	int max = 0;
	for(i=0; i<size; ++i)
		if (max < arr[i])
			max = arr[i];

	return max;
}

void print_histogram(int len[], int number_of_words)
{
	putchar('\n');
	for (i=0; i< number_of_words; ++i)
		printf("%d ", len[i]);
	putchar('\n');

	int max_len = get_max(len, number_of_words);
	int j=0;
	for (i=0; i<max_len; ++i)
	{
		for (j=0; j<number_of_words; ++j)
		{
			if ((max_len-i) <= len[j])
				putchar('|');
			else
				putchar(' ');
			putchar(' ');
		}
		putchar('\n');
	}
	putchar('\n');
}

int main()
{
	int len[MAX_WORDS];
	int number_of_words = 0;

	int i;
	for(i=0; i<MAX_WORDS; ++i)
	{
		len[i] = 0;
	}

	number_of_words = get_words_data(len, MAX_WORDS);
	
	print_histogram(len, number_of_words);

	return 0;
}



