/*
 * AVL Search Tree
 */

#include "05_avl_stree.h"

#include <stdio.h>
#include <stdlib.h>

static struct tree_node * get_new_node(int data);
static int height(struct tree_node * node);
static int max(int a, int b);
static struct tree_node * ll_rot(struct tree_node * node);
static struct tree_node * rr_rot(struct tree_node * node);

static void push(struct tree_node * node);
static struct tree_node * pop(void);
static int q_is_empty(void);

/* Returns the pointer to the node containing data or NULL if not found.
 * parent will contain pointer to the parent node. parent is NULL if data is found in root of the tree
 */
struct tree_node * find_data(struct tree_node * tree, int data, struct tree_node ** parent)
{
	*parent = NULL;
	while(tree != NULL)
	{
		if (tree->data == data)
			return tree;

		*parent = tree;
		if (tree->data > data)
			tree = tree->left;
		else
			tree = tree->right;
	}

	/* data not found in the tree */
	return NULL;
}

static struct tree_node * get_new_node(int data)
{
	struct tree_node * new_node;

	new_node = (struct tree_node *)malloc( sizeof(struct tree_node) );
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: Memory allocation failed while adding %d\n", data);
		exit(1);
	}

	new_node->data = data;
	new_node->left = new_node->right = NULL;
	new_node->height = 1;

	return new_node;
}

static int height(struct tree_node * node)
{
	if (node == NULL)
		return 0;
	return node->height;
}

static int max(int a, int b)
{
	return (a > b) ? a : b;
}

/*
 *	LL Rotation
 *     -------------
 *
 * ll_rot(A):
 *
 *        A		  B
 *       / \             / \
 *      B   T3   --->  T1   A
 *     / \                 / \
 *   T1*  T2             T2   T3
 *    
 *    ^
 *    |
 *    |
 *   Additon took place in T1 tree
 */
static struct tree_node * ll_rot(struct tree_node * node)
{
	struct tree_node * a = node;
	struct tree_node * b = node->left;

	a->left = b->right;
	b->right = a;

	a->height = max( height(a->left), height(a->right) ) + 1;
	b->height = max( height(b->left), height(b->right) ) + 1;

	return b;
}

/*
 *	RR Rotation
 *     -------------
 *
 * rr_rot(A):
 *
 *        A		  B
 *       / \             / \
 *     T1   B   --->    A   T3
 *         / \         / \
 *       T2   T3*    T1   T2
 *    
 *            ^
 *            |
 *            |
 *   Additon took place in T3 tree
 */
static struct tree_node * rr_rot(struct tree_node * node)
{
	struct tree_node * a = node;
	struct tree_node * b = node->right;

	a->right = b->left;
	b->left = a;

	a->height = max( height(a->left), height(a->right) ) + 1;
	b->height = max( height(b->left), height(b->right) ) + 1;

	return b;
}

/*
 *	LR Rotation
 *     -------------
 *
 *        A                             A                             
 *       / \                           / \                            ___C___
 *      B   T4     RR Rotation        C   T4       LL Rotation       /       \
 *     / \       -------------->     / \         -------------->    B         A
 *   T1   C                         B   T3                         / \       / \
 *       / \                       / \                           T1   T2   T3   T4
 *    T2*   T3                   T1   T2
 *    
 *     ^
 *     |
 *     |
 *   Additon took place in T2 tree
 */

struct tree_node * insert_node(struct tree_node * tree, int data)
{
	if (tree == NULL)
		return get_new_node(data);

	if (tree->data == data)
	{
		printf("%d already in the tree\n", data);
		return tree;
	}
	else if (tree->data > data)
		tree->left = insert_node(tree->left, data);
	else
		tree->right = insert_node(tree->right, data);

	tree->height = max( height(tree->left), height(tree->right) ) + 1;

	int balfact = height(tree->left) - height(tree->right);

	if (balfact > 1 && tree->left->data > data)
		tree = ll_rot(tree); /* Left Left Rotate */

	else if (balfact < -1 && tree->right->data < data)
		tree = rr_rot(tree); /* Right Right Rotate */

	else if (balfact > 1 && tree->left->data < data)
	{
 		/* Left Right Rotate */
		tree->left = rr_rot(tree->left);
		tree = ll_rot(tree);
	}

	else if (balfact < -1 && tree->right->data > data)
	{
 		/* Right Left Rotate */
		tree->right = ll_rot(tree->right);
		tree = rr_rot(tree);
	}

	return tree;
}

struct tree_node * delete_node(struct tree_node * tree, int data)
{
	if (tree == NULL)
	{
		printf("%d not found in tree\n", data);
		return NULL;
	}

	if (tree->data == data)
	{
		if (tree->left == NULL && tree->right == NULL)
		{
			free(tree);
			return NULL;
		}
		else if (tree->left != NULL && tree->right != NULL)
		{
			/* Both child present, find & return inorder successor */
			struct tree_node * rep_node = tree->right;
			int rep_data;

			while (rep_node->left != NULL)
				rep_node = rep_node->left;

			rep_data = rep_node->data;
			tree = delete_node(tree, rep_data);
			tree->data = rep_data;
			return tree;
		}
		else
			return (tree->left != NULL) ? tree->left : tree->right;
	}


	if (tree->data > data)
		tree->left = delete_node(tree->left, data);
	else 
		tree->right = delete_node(tree->right, data);

	tree->height = max( height(tree->left), height(tree->right) ) + 1;

	int balfact = height(tree->left) - height(tree->right);

	if ( balfact > 1)
	{
		/* Testing the balance factor of tree->left node */
		if ( (height(tree->left->left) - height(tree->left->right)) >= 0 )
		{
			/* Left Left Rotate */
			tree = ll_rot(tree);
		}
		else
		{
	 		/* Left Right Rotate */
			tree->left = rr_rot(tree->left);
			tree = ll_rot(tree);
		}
	}
	else if (balfact < -1)
	{
		/* Test the balance factor of tree->right node */
		if ( (height(tree->right->left) - height(tree->right->right)) < 0 )
		{
			/* Right Right Rotate */
			tree = rr_rot(tree);
		}
		else
		{
 			/* Right Left Rotate */
			tree->right = ll_rot(tree->right);
			tree = rr_rot(tree);
		}
	}
	

	return tree;
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
			printf("|%3d - %d| ", tree->data, tree->height);
			push(tree->left);
			push(tree->right);
			next_level += 2;
		}
		else
		{
			printf("|-------| ");
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


