/*
 * Linked list implemented using structures
 */

#include "04_ll_sorted.h"

#include <stdio.h>
#include <stdlib.h>

struct ll_node
{
	int data;
	struct ll_node * next;
};

static struct ll_node * start = NULL;

/* Private functions */
static void insert_after_node(struct ll_node * node, int data);
static void delete_after_node(struct ll_node * node);

void print_ll()
{
	struct ll_node * node;
	printf("\n[List] : ");
	for ( node = start; node != NULL; node = node->next)
		printf("%d ", node->data);
	printf("\n");
}

void traverse_ll(process_func_t process)
{
	struct ll_node * node;
	for ( node = start; node != NULL; node = node->next)
		process(node->data);
}

/* Return NULL if data not in list, otherwise returns a non-NULL pointer to node */
void * search_ll(int data)
{
	struct ll_node * node;
	for ( node = start; node != NULL; node = node->next)
		if (node->data == data)
			return node;

	return NULL;
}

/* (Static/Private function)
 * Insert after node. If node == NULL, insert at beginning */
static void insert_after_node(struct ll_node * node, int data)
{
	struct ll_node * new_node;

	new_node = (struct ll_node *) malloc( sizeof(struct ll_node) );
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}

	/* Put data into node */
	new_node->data = data;

	if (node == NULL) /* Insert at beginning */
	{
		/* Link the node */
		new_node->next = start;
		start = new_node;
	}
	else
	{
		/* Link the node */
		new_node->next = node->next;
		node->next = new_node;
	}
}

void insert_data(int data)
{
	if (start == NULL)
	{
		insert_after_node(NULL, data);
		return;
	}

	if ( search_ll(data) != NULL)
	{
		printf("%d already in the list\n", data);
		return;
	}

	struct ll_node * node;
	if (start->data > data)
		insert_after_node(NULL, data);
	else
	{
		for ( node = start; node->next != NULL; node = node->next)
			if (node->next->data > data)
				break;
		insert_after_node(node, data);
	}
}

/* If node == NULL, delete at the beginning of the list, otherwise delete at 'node' */
static void delete_after_node(struct ll_node * node)
{
	struct ll_node * del_node; /* Node to be deleted */

	if (node == NULL)
	{
		/* Deleting i.e edit list's links */
		del_node = start;
		start = del_node->next;
	}
	else
	{
		/* Deleting i.e edit list's links */
		del_node = node->next;
		node->next = del_node->next;
	}
	free(del_node);
}

void delete_data(int data)
{
	if (start == NULL)
	{
		fprintf(stderr, "Error: Deleting from empty list\n");
		return;
	}

	struct ll_node * node;

	if (start->data == data)
	{
		delete_after_node(NULL);
		return;
	}

	for ( node = start; node->next != NULL; node = node->next)
	{
		if (node->next->data == data)
		{
			delete_after_node(node);
			return;
		}
		if (node->next->data > data)
			break;
	}

	fprintf(stderr, "Error: %d not preset in list\n", data);
}


