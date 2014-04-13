/*
 * Print all the words in the input in decreasing order of their frequency in the input
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "e01_getword.h"

#define MAX_WORD_LEN 20


struct node
{
	char * word;
	int count;
	struct node * left;
	struct node * right;
};

struct node * add_word(struct node * tree, char * word);
struct node * add_count(struct node * count_tree, struct node * p);
struct node * make_count_tree(struct node * count_tree, struct node * word_tree);
void print_tree(struct node * tree);

int main()
{
	struct node * word_tree = NULL;
	struct node * count_tree = NULL;
	char word[MAX_WORD_LEN];

	while(getword(word, MAX_WORD_LEN) != EOF)
	{
		if (isalpha(*word))
		{
			word_tree = add_word(word_tree, word);
			if (word_tree == NULL)
				return 1;
		}
	}

	count_tree = make_count_tree(count_tree, word_tree);
	print_tree(count_tree);

	return 0;
}

struct node * add_word(struct node * tree, char * word)
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
		tree->left = tree->right = NULL;
		return tree;
	}

	int cmp;
	if ((cmp = strcmp(tree->word, word)) == 0)
	{
		++tree->count;
		return tree;
	}
	else if (cmp >= 1)
	{
		tree->left = add_word(tree->left, word);
		return tree;
	}
	else
	{
		tree->right = add_word(tree->right, word);
		return tree;
	}
}

struct node * add_count(struct node * count_tree, struct node * p)
{
	if (count_tree == NULL)
		return count_tree = p;

	if (count_tree->count > p->count)
	{
		count_tree->left = add_count(count_tree->left, p);
		return count_tree;
	}
	else
	{
		count_tree->right = add_count(count_tree->right, p);
		return count_tree;
	}
}

/* Create a new tree from word_tree which will be made using count rather than word */
struct node * make_count_tree(struct node * count_tree, struct node * word_tree)
{
	if (word_tree->left != NULL)
	{
		count_tree = make_count_tree(count_tree, word_tree->left);
		word_tree->left = NULL;
	}

	if (word_tree->right != NULL)
	{
		count_tree = make_count_tree(count_tree, word_tree->right);
		word_tree->right = NULL;
	}

	count_tree = add_count(count_tree, word_tree);
	assert(word_tree->left == NULL && word_tree->right == NULL);
	return count_tree;
}

void print_tree(struct node * tree)
{
	if (tree != NULL)
	{
		print_tree(tree->right);

		printf("%d: %s\n", tree->count, tree->word);
		free(tree->word);
		tree->word = NULL;

		print_tree(tree->left);
		free(tree);
		tree = NULL;
	}
	return;
}


