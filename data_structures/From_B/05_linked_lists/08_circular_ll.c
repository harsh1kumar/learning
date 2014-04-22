/*
 * Circular Linked List
 */

#include "08_circular_ll.h"

#include <stdio.h>
#include <stdlib.h>

struct ll_node
{
	int data;
	struct ll_node * next;
};

static struct ll_node * start = NULL;

/* Insert at the end of the list */
void insert_data(int data)
{
	struct ll_node * new_node;
	struct ll_node * node;

	new_node = (struct ll_node *) malloc( sizeof(struct ll_node) );
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: Memory allocation failed while adding %d\n", data);
		exit(EXIT_FAILURE);
	}

	new_node->data = data;

	if (start == NULL)
	{
		start = new_node;
		new_node->next = start;
		return;
	}

	for (node = start; node->next != start; node = node->next)
		;

	new_node->next = node->next;
	node->next = new_node;
	return;
}

void delete_data(int data)
{
	if ( start != NULL)
	{
		struct ll_node * node;
		struct ll_node * del_node;

		if (start->data == data)
		{
			del_node = start;
			if (start->next != start)
			{
				for (node = start; node->next != start; node = node->next)
					;
				start = start->next;
				node->next = start;
				
			}
			else
				start = NULL;
			free(del_node);
			return;
			
		}

		for (node = start; node->next != start; node = node->next)
		{
			if (node->next->data == data)
			{
				del_node = node->next;
				node->next = del_node->next;

				free(del_node);
				return;
			}
		}
	}
	printf("%d not found in list\n", data);
}

void print_ll(void)
{
	struct ll_node * node;

	printf("\n[List] : ");
	if ( start != NULL)
	{
		printf("%d ", start->data);
		for (node = start->next; node != start; node = node->next)
			printf("%d ", node->data);
	}
	printf("\n");
}

int search_ll(int data)
{
	int index = -1;
	struct ll_node * node = start;

	if ( start != NULL)
	{
		do
		{
			++index;
			if (node->data == data)
				return index;
			node = node->next;
		} while (node != start);
	}

	return -1;
}


