/*
 * Print list of all words along with a list of line numbers in which they appear
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "e03_getword.h"

#define MAX_WORD_LEN 20


struct node
{
	char * word;
	int * line;
	int count;
	struct node * left;
	struct node * right;
};

char * ignore_words[] = {	"the",
				"and"
			};

struct node * add_word(struct node * tree, char * word, int line);
void print_tree(struct node * tree);

int main()
{
	int line;
	int ignore;
	int i;
	struct node * tree = NULL;
	char word[MAX_WORD_LEN];

	line=1;
	while(getword(word, MAX_WORD_LEN) != EOF)
	{
		ignore=0;
		if (*word == '\n')
			++line;

		for(i=0; i< (sizeof ignore_words)/(sizeof ignore_words[0]); ++i)
			if (strcmp(word, ignore_words[i]) == 0)
				ignore = 1;
		
		if (isalpha(*word) && !ignore)
		{
			tree = add_word(tree, word, line);
			if (tree == NULL)
				return 1;
		}
	}

	print_tree(tree);

	return 0;
}

/* Adds nodes to the tree for new word. Adds line number for old number */
struct node * add_word(struct node * tree, char * word, int line)
{
	if (tree==NULL)
	{
		tree = (struct node *)malloc( sizeof(struct node) );
		if (tree==NULL)
		{
			fprintf(stderr, "Error: Memory allocation for struct node failed while adding %s\n", word);
			return tree;
		}

		tree->word = (char *)malloc( (strlen(word)+1) * sizeof(char) );
		if (tree->word == NULL)
		{
			fprintf(stderr, "Error: Memory allocation failed for word %s\n", word);
			free(tree);
			return NULL;
		}

		strcpy(tree->word, word);
		tree->count = 1;
		tree->line = (int *)malloc(sizeof(int));
		tree->line[0] = line;
		tree->left = tree->right = NULL;
		return tree;
	}

	int cmp;
	if ((cmp = strcmp(tree->word, word)) == 0)
	{
		++tree->count;
		tree->line = (int *)realloc(tree->line, tree->count*sizeof(int));
		tree->line[tree->count-1] = line;
		return tree;
	}
	else if (cmp >= 1)
	{
		tree->left = add_word(tree->left, word, line);
		return tree;
	}
	else
	{
		tree->right = add_word(tree->right, word, line);
		return tree;
	}
}

void print_tree(struct node * tree)
{	
	int i;

	if (tree != NULL)
	{
		print_tree(tree->left);

		printf("%s: ", tree->word);
		free(tree->word);
		tree->word = NULL;

		for (i=0; i<tree->count; ++i)
			printf("%d ", tree->line[i]);
		printf("\n");
		free(tree->line);
		tree->line = NULL;

		print_tree(tree->right);
		free(tree);
		tree = NULL;
	}
	return;
}


 
