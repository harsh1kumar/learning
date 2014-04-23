#include <stdio.h>

#include "01_stack_array.h"

int main()
{
	int i;

	printf("Pushing...\n");
	for (i=0; i<10; ++i)
		push(i);

	printf("Stack is%s full\n", (is_full() ? "": " not") );
	printf("Stack is%s empty\n", (is_empty() ? "": " not") );

	printf("Poping...\n");
	for (i=0; i<10; ++i)
		printf("%d\n", pop());

	printf("Stack is%s empty\n", (is_empty() ? "": " not") );
	printf("Stack is%s full\n", (is_full() ? "": " not") );

	return 0;
}