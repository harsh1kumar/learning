/*
 * M-Way search tree
 */

#include "06_mway_stree.h"

#include <stdio.h>
#include <stdlib.h>

static struct mway_node * getnode(int data);

/* Performs search in a recursive way. Returns NULL if data not found in the tree */
struct mway_node * search_data(struct mway_node * tree, int data)
{
	int i;

	if (tree == NULL)
		return NULL;

	for (i=0; i < tree->num_data; ++i)
	{
		if ( data == tree->data[i] )
			return tree;
		else if ( data < tree->data[i] )
			break;
	}

	return search_data(tree->links[i], data); 
}

static struct mway_node * getnode(int data)
{
	struct mway_node * new_node;
	int i;

	new_node = (struct mway_node *)malloc( sizeof(struct mway_node) );
	if ( new_node == NULL )
	{
		fprintf(stderr, "Error: Memory allocation failed while adding %d\n", data);
		exit(1);
	}

	new_node->data[0] = data;

	for (i=0; i < MWAY_ORDER; ++i)
		new_node->links[i] = NULL;

	new_node->num_data = 1;

	return new_node;
}

struct mway_node * insert_data(struct mway_node * tree, int data)
{
	int i, j;

	if (tree == NULL)
		return getnode(data);

	for (i=0; i < tree->num_data; i++)
		if (data < tree->data[i])
			break;

	if ( tree->num_data < MWAY_ORDER-1 )
	{
		/* Data can be added in this node itself */

		tree->links[tree->num_data+1] = tree->links[tree->num_data];
		for (j = tree->num_data-1; j >= i; --j)
		{
			tree->data[j+1] = tree->data[j];
			tree->links[j+1] = tree->links[j];
		}

		tree->data[i] = data;
		++(tree->num_data);
	}
	else
		tree->links[i] = insert_data(tree->links[i], data);

	return tree;
}

struct mway_node * delete_data(struct mway_node * tree, int data)
{
	int i, j;
	int rep_data;
	struct mway_node * rep_node;

	if ( tree == NULL )
	{
		printf("%d not found in the tree\n", data);
		return tree;
	}

	for (i=0; i < tree->num_data; i++)
	{
		if (data == tree->data[i])
			break;
		else if (data < tree->data[i])
		{
			tree->links[i] = delete_data(tree->links[i], data);
			return tree;
		}
	}

	if ( i == tree->num_data)
	{
		tree->links[tree->num_data] = delete_data(tree->links[tree->num_data], data);
		return tree;
	}

	/* If here, we delete the data */

	if ( tree->links[i] == NULL && tree->links[i+1] == NULL)
	{
		/* No child */
		if (tree->num_data == 1)
		{
			free(tree);
			tree = NULL;
		}
		else
		{
			for (j = i; j < tree->num_data-1; ++j)
			{
				tree->data[j] = tree->data[j+1];
				tree->links[j] = tree->links[j+1];
			}
			tree->links[tree->num_data-1] = tree->links[tree->num_data];

			tree->data[tree->num_data-1] = 0;
			tree->links[tree->num_data] = NULL;

			--(tree->num_data);
		}
	}
	else if ( tree->links[i] != NULL )
	{
		/* Left child present. Replace data with left child's greatest data */
		rep_node = tree->links[i];
		rep_data = rep_node->data[rep_node->num_data-1];

		tree->links[i] = delete_data(rep_node, rep_data);

		tree->data[i] = rep_data;
	}
	else
	{
		/* Right child is present, left child is NULL. Replace data with right child's smallest data */
		rep_node = tree->links[i+1];
		rep_data = rep_node->data[0];

		tree->links[i+1] = delete_data(rep_node, rep_data);

		tree->data[i] = rep_data;
	}

	return tree;
}

void inorder(struct mway_node * tree)
{
	int i;

	if (tree == NULL)
		return;

	printf(" [ ");

	for (i=0; i < tree->num_data; ++i)
	{
		inorder(tree->links[i]);
		printf("%d ", tree->data[i]);
	}

	inorder(tree->links[tree->num_data]);
	printf(" ] ");
}


