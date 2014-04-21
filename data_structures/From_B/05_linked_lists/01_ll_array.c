/*
 * Linked List Implementation using Arrays
 */

#include "01_ll_array.h"

#include <stdio.h>
#include <stdlib.h>

#define LL_MAX_SIZE 20

/* Linked List */
static int ll_data[LL_MAX_SIZE];
static int ll_link[LL_MAX_SIZE];

/* Linked List Pointers */
static int start = -1; /* -1 will stand for NULL */
static int empty = 0;

/* Private functions */
static void insert_after_node(int node, int data);
static void delete_after_node(int node);

void init_ll(int data)
{
	int i;
	if (start != -1)
	{
		fprintf(stderr, "Error: Trying to initialize a non-empty list\n");
		exit(EXIT_FAILURE);
	}

	ll_data[0] = data;
	ll_link[0] = -1;

	start = 0;
	empty = 1;

	/* Setting the links for the 'empty' list */
	for(i=1; i < LL_MAX_SIZE-1; ++i)
		ll_link[i] = i+1;
	ll_link[LL_MAX_SIZE-1] = -1;
	
}

void print_ll()
{
	int node;
	printf("\n[List] : ");
	for ( node = start; node != -1; node = ll_link[node])
		printf("%d ", ll_data[node]);
	printf("\n");
}

void traverse_ll(process_func_t process)
{
	int node;
	for ( node = start; node != -1; node = ll_link[node])
		process(ll_data[node]);
}

/* Return -1 if data not in list, otherwise returns the index(node) which is 0 or greater */
int search_ll(int data)
{
	int node;
	for ( node = start; node != -1; node = ll_link[node])
		if (ll_data[node] == data)
			return node;
	return -1;
}

void insert_at_begin(int data)
{
	if (start == -1)
	{
		fprintf(stderr, "Error: First initialize the list\n");
		return;
	}

	if (empty == -1)
	{
		fprintf(stderr, "Error: insert_at_end failed, no empty space available\n");
		return;
	}

	int new_node;

	/* Get empty node */
	new_node = empty;
	empty = ll_link[empty];

	/* Put data into node */
	ll_data[new_node] = data;

	/* Link the node */
	ll_link[new_node] = start;
	start = new_node;
}

void insert_at_end(int data)
{
	if (start == -1)
	{
		fprintf(stderr, "Error: First initialize the list\n");
		return;
	}

	if (empty == -1)
	{
		fprintf(stderr, "Error: insert_at_end failed, no empty space available\n");
		return;
	}

	int new_node;
	int node;

	for ( node = start; ll_link[node] != -1; node = ll_link[node])
		;

	/* Get empty node */
	new_node = empty;
	empty = ll_link[empty];

	/* Put data into node */
	ll_data[new_node] = data;
	ll_link[new_node] = -1;

	/* Link the node */
	ll_link[node] = new_node;
}

/* Insert 'data' after 'd' if found, otherwise insert at beginning */
void insert_after_d(int d, int data)
{
	if (start == -1)
	{
		fprintf(stderr, "Error: First initialize the list\n");
		return;
	}

	if (empty == -1)
	{
		fprintf(stderr, "Error: insert_at_end failed, no empty space available\n");
		return;
	}

	insert_after_node(search_ll(d), data);
}

/* (Static/Private function)
 * Insert after node. If node == -1, insert at beginning */
static void insert_after_node(int node, int data)
{
	if (node == -1)
		insert_at_begin(data);
	else
	{
		int new_node;

		/* Get empty node */
		new_node = empty;
		empty = ll_link[empty];

		/* Put data into node */
		ll_data[new_node] = data;

		/* Link the node */
		ll_link[new_node] = ll_link[node];
		ll_link[node] = new_node;
	}
}

/* If node == -1, delete at the beginning of the list, otherwise delete at 'node' */
static void delete_after_node(int node)
{
	if (start == -1)
	{
		fprintf(stderr, "Error: Deleting from empty list\n");
		return;
	}

	int del_node; /* Node to be deleted */

	if (node == -1)
	{
		/* Deleting i.e edit list's links */
		del_node = start;
		start = ll_link[del_node];
	}
	else
	{
		/* Deleting i.e edit list's links */
		del_node = ll_link[node];
		ll_link[node] = ll_link[del_node];
	}

	/* Add free space to 'empty' list*/
	ll_link[del_node] = empty;
	empty = del_node;
}

void delete_data(int data)
{
	int node;

	if (ll_data[start] == data)
	{
		delete_after_node(-1);
		return;
	}

	for ( node = start; ll_link[node] != -1; node = ll_link[node])
	{
		if (ll_data[ll_link[node]] == data)
		{
			delete_after_node(node);
			return;
		}
	}

	fprintf(stderr, "Error: %d not preset in list\n", data);
}



