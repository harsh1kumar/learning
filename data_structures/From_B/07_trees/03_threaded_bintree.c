/*
 * Threaded binary tree - Inorder one-way threading
 */

#include "03_threaded_bintree.h"

#include <stdio.h>
#include <stdlib.h>

void tt_inorder(struct tt_node * tree)
{
	while(tree != NULL)
	{
		while (tree->left != NULL)
			tree = tree->left;

		printf("%c ", tree->data);

		while (tree->rthread == THREAD)
		{
			tree = tree->right;
			printf("%c ", tree->data);
		}

		tree = tree->right;
	}
}

struct tt_node * tt_insert(struct tt_node * node, int data, int left)
{
	struct tt_node * new_node;

	new_node = (struct tt_node *)malloc( sizeof(struct tt_node) );
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: Memory allocation failed while adding %c\n", data);
		exit(1);
	}

	new_node->data = data;
	new_node->left = NULL;

	if (node == NULL)
	{
		new_node->right = NULL;
		new_node->rthread = NO_THREAD;
		return new_node;
	}

	if (left)
	{
		new_node->right = node;
		new_node->rthread = THREAD;
		node->left = new_node;
	}
	else
	{
		new_node->right = node->right;
		new_node->rthread = node->rthread;
		node->rthread = NO_THREAD;
		node->right = new_node;
	}

	return node;
}



