#include <stdio.h>
#include <stdlib.h>

#include "03_stack_ll.h"

int main()
{
	int i;
	int * pdata = NULL;
	struct stack_node * top = NULL;

	printf("Pushing...\n");
	for (i=0; i<10; ++i)
	{
		pdata = (int *) malloc( sizeof(int) );
		if (pdata == NULL)
		{
			fprintf(stderr, "Error: Memory allocation for data failed\n");
			exit(1);
		}
		*pdata = i;
		push(&top, pdata);
	}

	printf("Stack is%s full\n", (is_full(top) == TRUE ? "": " not") );
	printf("Stack is%s empty\n", (is_empty(top) == TRUE ? "": " not") );

	printf("Poping...\n");
	for (i=0; i<10; ++i)
	{
		printf("%d\n", *(int *)pop(&top));
		free(pdata);
		pdata = NULL;
	}

	printf("Stack is%s full\n", (is_full(top) == TRUE ? "": " not") );
	printf("Stack is%s empty\n", (is_empty(top) == TRUE ? "": " not") );

	return 0;
}



