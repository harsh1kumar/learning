/*
 * Circular Header Linked List implemented using structures
 */

#include "06_cir_header_ll.h"

#include <stdio.h>
#include <stdlib.h>

struct ll_node
{
	int data;
	struct ll_node * next;
};

static struct ll_node header = {0, &header};
static struct ll_node * start = &header;

/* Inserts at the end end of the list */
void insert_data(int data)
{
	struct ll_node * last_node;
	struct ll_node * new_node;

	new_node = (struct ll_node *)malloc( sizeof(struct ll_node) );
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: Memory allocation failed while inserting %d\n", data);
		return;
	}

	for (last_node = start; last_node->next != start; last_node = last_node->next)
		;

	new_node->data = data;
	new_node->next = start;

	last_node->next = new_node;
}

void delete_data(int data)
{
	struct ll_node * node;
	struct ll_node * del_node;
	for (node = start; node->next != start; node = node->next)
		if (node->next->data == data)
		{
			del_node = node->next;
			node->next = del_node->next;

			free(del_node);
			return;
		}

	printf("%d not found in the list, delete failed\n", data);
}

void print_ll()
{
	struct ll_node * node;
	printf("\n[List] : ");
	for (node = start->next; node != start; node = node->next)
		printf("%d ", node->data);
	printf("\n");
}

int search_ll(int data)
{
	int loc;
	struct ll_node * node;
	for (loc=-1, node = start->next; node != start; node = node->next)
	{
		++loc;
		if ( node->data == data )
			return loc;
	}
	return -1;
}

