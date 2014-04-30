/*
 * Binary tree implemented as a sequential array
 *
 * 	If index of parent is K, index of children will be 2K+1 & 2K+2
 * 	NULL tree will be denoted by -1 i.e tree can contain only positive values
 * 	User has to supply the array for the tree
 */

#include "02_bintree_arr.h"

#include <stdio.h>
#include <stdlib.h>

static void push(int data);
static int pop(void);
static int stack_is_empty(void);

void preorder(int * tree, int root)
{
	if (tree[root] == -1)
		return;

	printf("%c ", tree[root]);
	preorder(tree, 2*root + 1);
	preorder(tree, 2*root + 2);
}

void inorder(int * tree, int root)
{
	if (tree[root] == -1)
		return;

	inorder(tree, 2*root + 1);
	printf("%c ", tree[root]);
	inorder(tree, 2*root + 2);
}

void postorder(int * tree, int root)
{
	if (tree[root] == -1)
		return;

	postorder(tree, 2*root + 1);
	postorder(tree, 2*root + 2);
	printf("%c ", tree[root]);
}

/*******************
 *	STACK
 *******************/

#define MAX_STACK 20

static int stack[MAX_STACK];
static int sp = 0;

static void push(int data)
{
	if (sp == MAX_STACK)
	{
		fprintf(stderr, "Error: Stack Overflow\n");
		exit(1);
	}

	stack[sp++] = data;
}

static int pop()
{
	if (sp == 0)
	{
		fprintf(stderr, "Error: Stack Underflow\n");
		exit(1);
	}

	return stack[--sp];
}

static int stack_is_empty()
{
	return (sp == 0);
}


/* Non-recursive implementation of traversal algos using stack */

void preorder_stack(int * tree, int root)
{
	int ptr = root;

	while (tree[ptr] != -1)
	{
		printf("%c ", tree[ptr]);

		/* If right child exists, push its index into the stack */
		if (tree[2*ptr + 2] != -1)
			push(2*ptr + 2);

		if (tree[2*ptr + 1] != -1)
			ptr = 2*ptr + 1;
		else
		{
			if (stack_is_empty())
				break;
			else
				ptr = pop();
		}
				
	}
}

void inorder_stack(int * tree, int root)
{
	int ptr = root;

	while (1)
	{
		if (tree[ptr] == -1 )
		{
			if ( stack_is_empty() )
				break;
			else
			{
				ptr = pop();
				printf("%c ", tree[ptr]);
				ptr = 2*ptr + 2;
				continue;
			}
		}

		push(ptr);
		ptr = 2*ptr + 1;
	}
}

void postorder_stack(int * tree, int root)
{
	int ptr = root;

	while (tree[ptr] != -1)
	{
		push(ptr);

		/* If right child exists, push its index(multipled by -1) into the stack */
		if ( tree[2*ptr + 2] != -1 )
			push( -(2*ptr + 2) );

		if (tree[2*ptr + 1] != -1)
			ptr = 2*ptr + 1;
		else
		{
			while(1)
			{
				if ( stack_is_empty() )
					return;

				ptr = pop();
				if (ptr < 0)
				{
					ptr *= -1;
					break;
				}

				printf("%c ", tree[ptr]);
			}
		}
	}
}


