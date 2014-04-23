/*
 * A doubly linked list
 */

#include "10_doubly_ll.h"

#include <stdio.h>
#include <stdlib.h>

struct ll_node
{
	int data;
	struct ll_node * forw;
	struct ll_node * back;
};

struct ll_node * start = NULL;

/* Insert data at the end of the list */
void insert_data(int data)
{
	struct ll_node * node;
	struct ll_node * new_node;

	new_node = (struct ll_node *) malloc( sizeof(struct ll_node) );
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: Memory allocation failed while adding %d\n", data);
		exit(1);
	}

	new_node->data = data;

	if (start == NULL)
	{
		start = new_node;
		new_node->forw = NULL;
		new_node->back = NULL;
		return;
	}

	for (node = start; node->forw != NULL; node = node->forw)
		;

	new_node->back = node;
	new_node->forw = node->forw;
	node->forw = new_node;
}

void print_ll()
{
	struct ll_node * node;

	printf("\n[List] : ");
	if (start != NULL)
	{
		for (node = start; node->forw != NULL; node = node->forw)
			printf("%d ", node->data);
		printf("%d", node->data);
	}
	printf("\n");

	/* Now print reverse */
	printf("[List-]: ");
	if (start != NULL)
	{
		for ( ; node != start; node = node->back)
			printf("%d ", node->data);
		printf("%d", node->data);
	}
	printf("\n");
}

void delete_data(int data)
{
	struct ll_node * node;

	for (node = start; node != NULL; node = node->forw)
	{
		if (node->data == data)
		{
			if (node == start)
				start = node->forw;
			else
				node->back->forw = node->forw;

			if (node->forw != NULL)
				node->forw->back = node->back;
			free(node);
			return;
		}
	}
	printf("\n%d not in the list", data);
}


