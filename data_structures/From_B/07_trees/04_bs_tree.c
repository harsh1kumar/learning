/*
 * Binary Search Tree
 */

#include "04_bs_tree.h"

#include <stdio.h>
#include <stdlib.h>

static struct tree_node * delnode_2child(struct tree_node * parent, struct tree_node * del_node);

static void push(struct tree_node * node);
static struct tree_node * pop(void);
static int q_is_empty(void);

/* 
 * Returns the pointer to the node with data, NULL otherwise. 
 *	parent will have the pointer of parent of node having data.
 *	parent will be NULL if data is found at root of tree.
 */
struct tree_node * find(struct tree_node * tree, int data, struct tree_node ** parent)
{
	
	*parent = NULL;

	while (tree != NULL)
	{
		if (tree->data == data)
			break;

		*parent = tree;
		if (tree->data > data)
			tree = tree->left;
		else
			tree = tree->right;
	}

	return tree;
}

/* Returns the pointer to modified parent */
struct tree_node * insert_node(struct tree_node * tree, int data)
{
	struct tree_node * new_node;
	struct tree_node * parent = NULL;

	if ( find(tree, data, &parent) != NULL)
		printf("%d already in the tree\n", data);
	else
	{
		new_node = (struct tree_node *)malloc( sizeof(struct tree_node) );
		if (new_node == NULL)
		{
			fprintf(stderr, "Error: Memory allocation failed while adding %d\n", data);
			exit(1);
		}
		new_node->data = data;
		new_node->left = new_node->right = NULL;

		if (parent == NULL)
			tree = new_node; /* This node must be root of the tree */
		else if (parent->data > data )
			parent->left = new_node;
		else
			parent->right = new_node;
	}

	return tree;
}

struct tree_node * delete_node(struct tree_node * tree, int data)
{
	struct tree_node * parent = NULL;
	struct tree_node * del_node;

	if (tree->data == data)
	{
		if (tree->left == NULL && tree->right == NULL)
			tree = NULL;
		else if (tree->left != NULL && tree->right != NULL)
			tree = delnode_2child(NULL, tree);
		else
			tree = (tree->left != NULL) ? tree->left : tree->right;

		return tree;
	}

	if ( (del_node=find(tree, data, &parent)) == NULL)
	{
		printf("%d not found in the tree\n", data);
	}
	else
	{
		if (del_node->left == NULL && del_node->right == NULL)
		{
			/* del_node has no child */
			if (parent->left == del_node)
				parent->left = NULL;
			else
				parent->right = NULL;
			free(del_node);
		}
		else if (del_node->left != NULL && del_node->right != NULL)
		{
			/* del_node has two children */
			parent = delnode_2child(parent, del_node);
		}
		else
		{
			/* del_node has only one child */
			if (parent->left == del_node)
				parent->left = (del_node->left != NULL) ? del_node->left : del_node->right;
			else
				parent->right = (del_node->left != NULL) ? del_node->left : del_node->right;
			free(del_node);
		}
	}

	return tree;
}

/* Delete del_node. Returns pointer to modified parent */
static struct tree_node * delnode_2child(struct tree_node * parent, struct tree_node * del_node)
{
	struct tree_node * rep_node; /* Replace node which is the inorder successor of del_node */
	struct tree_node * rep_node_parent; /* Parent of Replace node */
	int rep_data; /* Data stored in Replace node */

	/* Finding inorder successor */
	rep_node = del_node->right;
	rep_node_parent = del_node;
	while (rep_node->left != NULL)
	{
		rep_node_parent = rep_node;
		rep_node = rep_node->left;
	}

	/* Deleting rep_node from the tree */
	rep_data = rep_node->data;
	delete_node(rep_node_parent, rep_data);

	del_node->data = rep_data;
	if (parent == NULL)
		parent = del_node;

	return parent;
}


void print_tree(struct tree_node * tree)
{
	int curr_level = 1;
	int next_level = 0;

	printf("\n-----------------------------------\n");
	push(tree);
	while ( !q_is_empty())
	{
		tree = pop();
		--curr_level;
		if (tree != NULL)
		{
			printf("%3d ", tree->data);
			push(tree->left);
			push(tree->right);
			next_level += 2;
		}
		else
		{
			printf("(*) ");
		}
		if (curr_level == 0)
		{
			printf("\n");
			curr_level = next_level;
			next_level = 0;
		}
	}
	printf("-----------------------------------\n\n");
}

/*** A Circular Queue ***/

#define MAX_QUEUE 10
static struct tree_node * queue[MAX_QUEUE];
static int front = -1;
static int rear = -1;

static void push(struct tree_node * node)
{
	if ( (front == 0 && rear == MAX_QUEUE-1) || (front == rear+1))
	{
		fprintf(stderr, "Error: Queue Overflow");
		exit(1);
	}

	if ( rear == -1)
		front = rear = 0;
	else if (rear == MAX_QUEUE-1)
		rear = 0;
	else
		++(rear);

	queue[rear] = node;
}

static struct tree_node * pop(void)
{
	struct tree_node * retval;

	if ( front == -1 )
	{
		fprintf(stderr, "Error: Queue Underflow\n");
		exit(1);
	}

	retval = queue[front];
	if (front == rear)
		front = rear = -1;
	else if (front == MAX_QUEUE-1)
		front = 0;
	else
		++(front);

	return retval;
}

static int q_is_empty()
{
	return (front == -1);
}
