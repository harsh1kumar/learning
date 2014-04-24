/*
 * Stack implemented as a linked list which is dynamically allocated.
 */

#include "03_stack_ll.h"

#include <stdio.h>
#include <stdlib.h>

/*******************
 *	STACK
 *******************/

void push(struct stack_node ** ptop, void * data)
{
	struct stack_node * new_node;

	new_node = (struct stack_node *) malloc( sizeof(struct stack_node) );
	if ( new_node == NULL )
	{
		fprintf(stderr, "Error: Memory allocation failed while adding data\n");
		exit(1);
	}

	new_node->data = data;
	new_node->next = *ptop;

	*ptop = new_node;
}

void * pop(struct stack_node ** ptop)
{
	struct stack_node * del_node;
	void * del_data;

	if ( is_empty(*ptop) == TRUE )
	{
		fprintf(stderr, "Error: Stack Underflow\n");
		exit(1);
	}

	del_node = *ptop;
	*ptop = del_node->next;
	del_data = del_node->data;

	free(del_node);
	return del_data;
}

Bool is_empty(const struct stack_node * top)
{
	return ((top == NULL) ? TRUE : FALSE );
}

Bool is_full(const struct stack_node * top)
{
	/* Stack is dynamically allocated, never full */
	return FALSE;
}



