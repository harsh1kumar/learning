#include "e03_stack.h"
#include <stdio.h>

#define STACK_SIZE 20

double stack[STACK_SIZE];
int sp = 0; /* Stack pointer */

void push(double num)
{
	if (sp < STACK_SIZE)
		stack[sp++] = num;
	else
		fprintf(stderr, "Pushing into a full stack\n");
}

double pop(void)
{
	if (sp > 0)
		return stack[--sp];
	else
		fprintf(stderr, "Poping from a empty stack\n");
}
