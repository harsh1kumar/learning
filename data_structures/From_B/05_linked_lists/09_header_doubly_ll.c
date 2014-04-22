/*
 * Doubly linked circular header linked list
 */

#include "09_header_doubly_ll.h"

#include <stdio.h>
#include <stdlib.h>

struct ll_node
{
	int data;
	struct ll_node * forw;
	struct ll_node * back;
};

static struct ll_node header = { 0, &header, &header};
static struct ll_node * start = &header;

/* Insert at the end of the list */
void insert_data(int data)
{
	struct ll_node * node;
	struct ll_node * new_node;

	new_node = (struct ll_node *) malloc( sizeof(struct ll_node) );
	if ( new_node == NULL )
	{
		fprintf(stderr, "Error: Memory allocation failed while adding %d\n", data);
		exit(EXIT_FAILURE);
	}

	for ( node = start; node->forw != start; node = node->forw )
		;

	new_node->data = data;

	node->forw->back = new_node;
	new_node->forw = node->forw;

	new_node->back = node;
	node->forw = new_node;

}

void delete_data(int data)
{
	struct ll_node * node;

	for ( node = start->forw; node != start; node = node->forw )
		if ( node->data == data)
		{
			node->back->forw = node->forw;
			node->forw->back = node->back;
			free(node);
			return;
		}

	printf("%d not in list\n", data);
}

void print_ll(void)
{
	print_ll_fw();
	print_ll_bk();
}

void print_ll_fw(void)
{
	struct ll_node * node;

	printf("\n[List] : ");
	for ( node = start->forw; node != start; node = node->forw )
		printf("%02d ", node->data);
	printf("\n");
}

void print_ll_bk(void)
{
	struct ll_node * node;

	printf("[List-]: ");
	for ( node = start->back; node != start; node = node->back )
		printf("%02d ", node->data);
	printf("\n");
}

int search_ll(int data)
{
	int index = -1;
	struct ll_node * node;

	for ( node = start->forw; node != start; node = node->forw )
	{
		++index;
		if (node->data == data)
			return index;
	}
	return -1;
}
