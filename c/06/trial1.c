/*
 * Print the count of all the words in the input
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "e01_getword.h"

#define MAX_WORD_LEN 20

struct node
{
	char * word;
	int count;
	struct node * left;
	struct node * right;
};

int add_word(char * word, struct node ** ptree);
void print_words(struct node ** ptree);

int main()
{
	char word[MAX_WORD_LEN];
	int c;
	struct node * tree = NULL;

	while((c=getword(word, MAX_WORD_LEN)) != EOF)
	{
		if (isalpha(*word) || *word == '_')
			if (add_word(word, &tree) == 0)
				return 1;
	}
	
	print_words(&tree);
}

/* Returns 1 is successful, 0 if unsuccessful */
int add_word(char * word, struct node ** ptree)
{
	int cmp;
	struct node * next;

	if (*ptree == NULL)
	{
		/* Word not present, adding a node */
		*ptree = (struct node *)malloc(sizeof(struct node));
		if (*ptree == NULL)
		{
			fprintf(stderr, "Error: Memory allocation failed creating node for %s\n", word);
			return 0;
		}
		(*ptree)->word = (char *)malloc( (strlen(word)+1) * sizeof(char) );
		if ((*ptree)->word == NULL)
		{
			fprintf(stderr, "Error: Memory allocation failed while storing %s\n", word);
			return 0;
		}
		strcpy((*ptree)->word, word);
		(*ptree)->count=1;
		(*ptree)->left = (*ptree)->right = NULL;
		return 1;
	}
	
	if ((cmp = strcmp((*ptree)->word, word)) == 0)
	{
		++(*ptree)->count;
		return 1;
	}
	else if (cmp >= 1)
		return add_word(word, &(*ptree)->left);
	else
		return add_word(word, &(*ptree)->right);
}

void print_words(struct node ** ptree)
{
	if (*ptree != NULL)
	{
		print_words(&(*ptree)->left);
		printf("%4d : %s\n", (*ptree)->count, (*ptree)->word);
		free((*ptree)->word);
		print_words(&(*ptree)->right);
		free(*ptree);
	}
	return;
}

