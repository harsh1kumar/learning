/*
 * Linked list implemented using structures
 */

#include "03_ll.h"

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

void insert_at_begin(int data)
{
	struct ll_node * node;

	node = (struct ll_node *) malloc( sizeof(struct ll_node) );
	if (node == NULL)
	{
		fprintf(stderr, "Error: Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}

	node->data = data;
	node->next = start;
	start = node;
}

/* Insert 'data' after 'd' if found, otherwise insert at beginning */
void insert_after_d(int d, int data)
{
	if (start == NULL)
	{
		insert_at_begin(data);
		return;
	}

	insert_after_node(search_ll(d), data);
}

void insert_at_end(int data)
{
	if (start == NULL)
	{
		insert_at_begin(data);
		return;
	}

	struct ll_node * node;
	for (node = start; node->next != NULL; node = node->next)
		;

	insert_after_node(node, data);
}

static void insert_after_node(struct ll_node * node, int data)
{
	struct ll_node * p;

	if (node == NULL)
	{
		insert_at_begin(data);
		return;
	}

	p = (struct ll_node *) malloc( sizeof(struct ll_node) );
	if (p == NULL)
	{
		fprintf(stderr, "Error: Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}

	p->data = data;
	p->next = node->next;
	node->next = p;
}

/* If node is NULL, delete the first node */
static void delete_after_node(struct ll_node * node)
{
	struct ll_node * del_node;

	if (node == NULL)
	{
		del_node = start;
		start = del_node->next;
	}
	else
	{
		del_node = node->next;
		node->next = del_node->next;
	}
	free(del_node);
}

void delete_data(int data)
{
	struct ll_node * node;

	if (start->data == data)
	{
		delete_after_node(NULL);
		return;
	}

	for (node = start; node->next != NULL; node = node->next)
	{
		if (node->next->data == data)
		{
			delete_after_node(node);
			return;
		}
	}
	
	fprintf(stderr, "Error: %d not preset in list\n", data);
}

void print_ll()
{
	struct ll_node * node;

	printf("\n[List] : ");
	for (node = start; node != NULL; node = node->next)
		printf("%d ", node->data);
	printf("\n");
}

void traverse_ll(process_func_t process)
{
	struct ll_node * node;
	for (node = start; node != NULL; node = node->next)
		process(node->data);
}

/* Returns NULL if not found, else the pointer to ll_node type-casted as void pointer */
void * search_ll(int data)
{
	struct ll_node * p;

	for (p = start; p != NULL; p = p->next)
		if (p->data == data)
			return p;

	return NULL; /* Not found */
}


