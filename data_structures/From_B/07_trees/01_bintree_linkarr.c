/*
 * Binary tree implemented using linked array
 *
 *	User has to supply 
 *		3 arrays: data, left, right all of same dimension
 *		tree: index of root of tree
 *		avail: index of the first free space in the arrays
 */

#include "01_bintree_linkarr.h"

#include <stdio.h>
#include <stdlib.h>

void preorder(int * data, int * left, int * right, int tree)
{
	if (tree == -1)
		return;

	printf("%c ", data[tree]);
	preorder(data, left, right, left[tree]);
	preorder(data, left, right, right[tree]);
}

void inorder(int * data, int * left, int * right, int tree)
{
	if (tree == -1)
		return;

	inorder(data, left, right, left[tree]);
	printf("%c ", data[tree]);
	inorder(data, left, right, right[tree]);
}

void postorder(int * data, int * left, int * right, int tree)
{
	if (tree == -1)
		return;

	postorder(data, left, right, left[tree]);
	postorder(data, left, right, right[tree]);
	printf("%c ", data[tree]);
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
void preorder_stack(int * data, int * left, int * right, int tree)
{
	int ptr = tree;

	while (ptr != -1)
	{
		printf("%c ", data[ptr]);

		/* If right child exists, push its index into the stack */
		if (right[ptr] != -1)
			push(right[ptr]);

		if (left[ptr] != -1)
			ptr = left[ptr];
		else
		{
			if ( stack_is_empty() )
				break;
			else
				ptr = pop();
		}
	}
}

void inorder_stack(int * data, int * left, int * right, int tree)
{
	int ptr = tree;

	while (1)
	{
		if (ptr == -1)
		{
			if ( stack_is_empty() )
				break;
			else
			{
				ptr = pop();
				printf("%c ", data[ptr]);
				ptr = right[ptr];
				continue;
			}
		}

		push(ptr);
		ptr = left[ptr];
	}
}

void postorder_stack(int * data, int * left, int * right, int tree)
{
	int ptr = tree;

	while (ptr != -1)
	{
		push(ptr);

		if ( right[ptr] != -1)
			push( (-1)*right[ptr] );

		if ( left[ptr] != -1 )
			ptr = left[ptr];
		else
		{
			while (1)
			{
				if ( stack_is_empty() )
					return;

				ptr = pop();
				if (ptr < 0)
				{
					ptr *= -1;
					break;
				}

				printf("%c ", data[ptr]);
			}
		}
	}
}



