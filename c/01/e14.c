#include <stdio.h>

/*
 * Prints a histogram of freqency of alphabets in the input
 */

#define NUM_ALPHA 26

void get_data(int count[], int size)
{
	int c;
	while((c=getchar()) != EOF)
	{
		if (c >= 'A' && c <= 'Z')
			c = c - 'A' + 'a';

		if (c >= 'a' && c <= 'z')
			++count[c-'a'];
	}
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
	int i=0;

	putchar('\n');
	for (i=0; i< number_of_words; ++i)
		printf("%c ", 'a'+i);
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
	int count[NUM_ALPHA];

	int i;
	for(i=0; i<NUM_ALPHA; ++i)
	{
		count[i] = 0;
	}

	get_data(count, NUM_ALPHA);
	
	print_histogram(count, NUM_ALPHA);

	return 0;
}



