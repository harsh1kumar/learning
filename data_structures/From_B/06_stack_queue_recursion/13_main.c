#include <stdio.h>
#include <stdlib.h>

#include "13_cir_queue.h"

int main()
{
	struct queue q;
	int data;

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

				q_insert(&q, data);
				printf("Done\n");
				break;

			case (2):
				data = q_delete(&q);
				printf("\nData = %d\n", data);
				break;

			default:
				exit(1);
				break;
		}
	}
	return 0;
}
