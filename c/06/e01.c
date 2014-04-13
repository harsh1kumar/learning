/*
 * getword()
 */ 

#include <stdio.h>

#include "e01_getword.h"

#define MAX_WORD_LEN 20

int main()
{
	char word[MAX_WORD_LEN];

	while(getword(word, MAX_WORD_LEN) != EOF)
		printf("%s\n", word);

	return 0;
}



