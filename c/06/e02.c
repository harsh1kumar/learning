/*
 * Print alphabetically each group of variables in a C program that are identical in their first 6 characters, but different afterwards
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "e01_getword.h"

#define MAX_WORD_LEN 20
#define DEF_IDENTI_LEN 6

/*
 * node makes a tree.
 * It has a pointer to a subnode.
 * 
 * subnode also makes a tree, but of different kind.
 * Every tree made by subnodes will have the same first 'var_identical_len' characters
 * The count of node tree should contain the number of subnodes in subnode tree.
 */
struct subnode
{
	char * word;
	struct subnode * left;
	struct subnode * right;
};

struct node
{
	struct subnode * sub;
	int count;
	struct node * left;
	struct node * right;
};

int add_subnode(char * word, struct subnode ** p);
int add_word_subnode(char * word, struct subnode * p);
int add_node(char * word, struct node ** ptree);
int add_word(char * word, struct node ** ptree, int var_identical_len);

void print_subnode(struct subnode ** p);
void print_words(struct node ** ptree);

int is_variable(char * word, char * word_next);

int main(int argc, char * argv[])
{
	char word[MAX_WORD_LEN];
	char word_next[MAX_WORD_LEN];
	int var_identical_len = DEF_IDENTI_LEN;
	struct node * tree = NULL;

	if (argc > 2)
	{
		fprintf(stderr, "Usage: %s [n]\n", *argv);
		return 1;
	}

	/* Read from commandline if available */
	if (argc == 2)
		var_identical_len = atoi(*(argv+1));

	if (getword(word, MAX_WORD_LEN) != EOF)
		while(getword(word_next, MAX_WORD_LEN) != EOF)
		{
			if (is_variable(word, word_next) && strlen(word) >= var_identical_len)
				if (add_word(word, &tree, var_identical_len) == 0)
					return 1;
			strcpy(word, word_next);
		}
	
	print_words(&tree);
}




/*******************************************************************
 * 	Data Structures Operations for storing variable names
 *******************************************************************/

int add_subnode(char * word, struct subnode ** p)
{
	*p = (struct subnode *)malloc(sizeof(struct subnode));
	if (*p == NULL)
	{
		fprintf(stderr, "Error: Memory allocation failed for subnode for storing %s\n", word);
		return 0;
	}

	(*p)->word = (char *)malloc( (strlen(word)+1) * sizeof(char) );
	if ((*p)->word == NULL)
	{
		fprintf(stderr, "Error: Memory allocation failed while storing %s\n", word);
		return 0;
	}
	strcpy((*p)->word, word);
	(*p)->left = (*p)->right = NULL;

	return 1;
}

int add_word_subnode(char * word, struct subnode * p)
{
	int cmp;

	if ((cmp = strcmp(p->word, word)) == 0)
		return 1;
	else if (cmp >= 1)
	{
		if (p->left != NULL)
			return add_word_subnode(word, p->left);
		else
			return add_subnode(word, &(p->left));
	}
	else
	{
		if (p->right != NULL)
			return add_word_subnode(word, p->right);
		else
			return add_subnode(word, &(p->right));
	}
}

/* Adds a new node & stores 'word' in it */
int add_node(char * word, struct node ** ptree)
{
	*ptree = (struct node *)malloc(sizeof(struct node));
	if (*ptree == NULL)
	{
		fprintf(stderr, "Error: Memory allocation failed creating node for %s\n", word);
		return 0;
	}

	if (add_subnode(word, &((*ptree)->sub)) == 0)
		return 0;

	(*ptree)->count=1;
	(*ptree)->left = (*ptree)->right = NULL;

	return 1;
}

/* Returns 1 is successful, 0 if unsuccessful */
int add_word(char * word, struct node ** ptree, int var_identical_len)
{
	int cmp;

	if (*ptree == NULL)
		return add_node(word, ptree); /* Word not present, adding a node */

	/* Comparing the first 'var_identical_len' characters */
	if ((cmp = strncmp((*ptree)->sub->word, word, var_identical_len)) == 0)
	{
		++(*ptree)->count;
		return add_word_subnode(word, (*ptree)->sub);
	}
	else if (cmp >= 1)
		return add_word(word, &(*ptree)->left, var_identical_len);
	else
		return add_word(word, &(*ptree)->right, var_identical_len);
}



/**********************
 * 	Prints
 **********************/

void print_subnode(struct subnode ** p)
{
	if (*p != NULL)
	{
		print_subnode(&(*p)->left);
		printf("%s\n", (*p)->word);
		free((*p)->word);
		print_subnode(&(*p)->right);
		free(*p);
	}
	return;
}

void print_words(struct node ** ptree)
{
	if (*ptree != NULL)
	{
		print_words(&(*ptree)->left);
		if ((*ptree)->sub->left != NULL || (*ptree)->sub->right != NULL)
		{
			/* If here, then (*ptree) has atleast 2 words */
			print_subnode(&(*ptree)->sub);
			printf("\n");
		}
		print_words(&(*ptree)->right);
		free(*ptree);
	}
	return;
}



/***********************************
 * 	Variable Name Detection
 * *********************************/

static char * types[] = {	"void",
				"char",
				"int",
				"short",
				"long",
				"float",
				"double"
			};

static char * types_skip[] = {	"struct",
				"enum",
				"static",
				"register",
				"extern"
			};

enum Bool {FALSE, TRUE};

/* Returns 1 if word is a variable name */
int is_variable(char * word, char * word_next)
{
	static enum Bool new_command = TRUE; /* True when the command has possibility of presence of variables*/
	static enum Bool declaration = FALSE; /* True when the command is a declaration/defination */
	static enum Bool value = FALSE; /* True if next words will be part of value */
	static enum Bool paren = FALSE; /* True if array index */
	static enum Bool func_args = FALSE; /* True if function arguments */
	static enum Bool skip_next = FALSE; /* True if next found word is not to be considered variable */
	int i;

	if (*word == '*')
		return 0;

	if (	*word == ';' || 
		*word == '{' || 
		*word == '}' || 
		*word == '(' || 
		*word == ')' || 
		(*word == ',' && func_args == TRUE)
	   )
	{
		/* Next words will be from a new command */
		new_command = TRUE;
		declaration = FALSE;
		value = FALSE;
		paren = FALSE;

		if (*word == '(')
			func_args = TRUE;
		else
			func_args = FALSE;
		return 0;
	}

	if (new_command == TRUE)
	{
		for(i=0; i<(sizeof types)/(sizeof types[0]); ++i)
		{
			if (strcmp(types[i], word) == 0)
			{
				declaration = TRUE;
				skip_next = FALSE;
				return 0;
			}
		}

		for(i=0; i<(sizeof types_skip)/(sizeof types_skip[0]); ++i)
		{
			if (strcmp(types_skip[i], word) == 0)
			{
				declaration = TRUE;
				skip_next = TRUE;
				return 0;
			}
		}

		if (declaration == FALSE)
		{
			/* word not found in types[] */
			new_command = FALSE;
			return 0;
		}

		if (*word == ',')
		{
			value = FALSE;
			return 0;
		}

		if (*word == ']')
		{
			paren = FALSE;
			return 0;
		}

		if (value == FALSE && paren == FALSE)
		{
			if (isalpha(*word) || *word == '_')
			{
				if (*word_next == '(')
					return 0;
				if (skip_next == TRUE)
				{
					skip_next = FALSE;
					return 0;
				}
				return 1; /* Is a variable name */
			}
			else if (*word == '=')
			{
				value = TRUE; /* A value of a variable starts */
				return 0;
			}
			else if (*word == '[')
			{
				paren = TRUE;
				return 0;
			}
		}
		
	}
	
	return 0;
}


