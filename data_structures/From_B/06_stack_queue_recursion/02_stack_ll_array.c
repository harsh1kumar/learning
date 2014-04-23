/*
 * Stack implemented as a linked list.
 * Linked list implemented using arrays, thus this implementation is of not much use.
 */

#include "02_stack_ll_array.h"

#include <stdio.h>
#include <stdlib.h>


/*******************
 *	STACK
 *******************/

/* Private functions */
static void ll_insert_at_begin(int data);
static int ll_remove_at_begin(void);
static int ll_is_full(void);
static int ll_is_empty(void);

void push(int data)
{
	if ( ll_is_full() )
	{
		fprintf(stderr, "Error: Stack Overflow\n");
		exit(1);
	}

	ll_insert_at_begin(data);
}

int pop(void)
{
	if ( ll_is_empty() )
	{
		fprintf(stderr, "Error: Stack Underflow\n");
		exit(1);
	}
	
	return ll_remove_at_begin();
}

int is_empty(void)
{
	return ll_is_empty();
}

int is_full(void)
{
	return ll_is_full();
}

/*************************
 *	LINKED LIST
 *************************/

#define MAX_LL 10

static int ll_data[MAX_LL];
static int ll_link[MAX_LL];

static int ll_start = -1;
static int ll_empty = 0;

static void ll_insert_at_begin(int data)
{
	if ( ll_is_full() )
	{
		fprintf(stderr, "Error: LL Overflow. No space left for allocation for stack\n");
		exit(1);
	}

	if ( ll_is_empty() )
	{
		int i;

		for (i=0; i<MAX_LL-1; ++i)
			ll_link[i] = i+1;
		ll_link[MAX_LL-1] = -1;
	}

	int new_node;
	new_node = ll_empty;
	ll_empty = ll_link[ll_empty];

	ll_data[new_node] = data;
	ll_link[new_node] = ll_start;
	ll_start = new_node;
}

/*
 * Returns the data of the node removed;
 */
static int ll_remove_at_begin(void)
{
	int del_node;

	if ( ll_is_empty() )
	{
		fprintf(stderr, "Error: LL Underflow.\n");
		exit(1);
	}

	del_node = ll_start;
	ll_start = ll_link[del_node];

	ll_link[del_node] = ll_empty;
	ll_empty = del_node;

	return ll_data[del_node];
}

static int ll_is_empty()
{
	return (ll_start == -1);
}

static int ll_is_full()
{
	return (ll_empty == -1);
}

