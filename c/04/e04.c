/*
 * Some stack funtions
 */

#include <stdio.h>

void push(int num);
int pop(void);
int gettop(void);
void duplicate_top(void);
void swap_top(void);
void clear_stack(void);

int main()
{
	push(1);
	push(2);
	push(3);
	push(4);

	printf("Top: %d\n", gettop());
	
	printf("Duplicating Top\n");
	duplicate_top();
	printf("Poped value: %d\n", pop());
	printf("Top: %d\n", gettop());

	printf("Swapping top\n");
	swap_top();
	printf("Pop val1: %d\n", pop());
	printf("Pop val2: %d\n", pop());

	printf("Clearing stack\n");
	clear_stack();
	pop();

	return 0;
}


#define STACK_SIZE 8

int stack[STACK_SIZE];
int sp = 0;

void push(int num)
{
	if (sp < STACK_SIZE)
		stack[sp++] = num;
	else
		fprintf(stderr, "Pushing into a full stack\n");
}

int pop(void)
{
	if (sp > 0)
		return stack[--sp];
	else
		fprintf(stderr, "Poping from a empty stack\n");
}

int gettop()
{
	if (sp > 0)
		return stack[sp-1];
	else
		fprintf(stderr, "Stack Empty\n");
}

void duplicate_top()
{
	push(gettop());
}

void swap_top()
{
	int temp = stack[sp-1];
	stack[sp-1] = stack[sp-2];
	stack[sp-2] = temp;
}

void clear_stack()
{
	sp = 0;
}