/*
 * Stack implemented using array
 */

#include "01_stack_array.h"

#include <stdio.h>
#include <stdlib.h>

static int stack[MAX_STACK];
static int sp = 0; /* Stack pointer */

void push(int data)
{
	if ( is_full() )
	{
		fprintf(stderr, "Error: Stack Overflow while inserting %d\n", data);
		exit(1);	
	}

	stack[sp++] = data;
}

int pop(void)
{
	if ( is_empty() )
	{
		fprintf(stderr, "Error: Stack Underflow\n");
		exit(1);
	}

	return stack[--sp];
}

int is_empty(void)
{
	return !sp;
}

int is_full(void)
{
	return (sp == MAX_STACK);
}
