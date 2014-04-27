#include <stdio.h>
#include <stdlib.h>

#include "11_queue.h"

int main()
{
	struct queue q;
	int data;
	int * pdata;

	q_init(&q);
	while (1)
	{
		printf("Enter\n\t1: Insert\n\t2: Delete\n\t3: Exit\n\t: ");
		scanf("%d", &data);
		switch (data)
		{
			case (1):
				printf("\nEnter Number: ");
				scanf("%d", &data);

				if ( ( pdata = (int*)malloc(sizeof(int)) ) == NULL)
				{
					fprintf(stderr, "Error: Memory allocation failed\n");
					exit(1);
				}
				*pdata = data;

				q_insert(&q, pdata);
				printf("Done\n");
				break;

			case (2):
				pdata = q_delete(&q);
				printf("\nData = %d\n", *pdata);
				free(pdata);
				break;

			default:
				exit(1);
				break;
		}
	}

	return 0;
}
 
