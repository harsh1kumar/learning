#include <stdio.h>
#include <stdlib.h>

#include "10_queue_arr.h"

#define MAX_QUEUE 10

int main()
{
	int front;
	int rear;
	int queue[MAX_QUEUE];
	int data;

	q_init(&front, &rear);
	while (1)
	{
		printf("Enter\n\t1: Insert\n\t2: Delete\n\t3: Exit\n\t: ");
		scanf("%d", &data);
		switch (data)
		{
			case (1):
				printf("\nEnter Number: ");
				scanf("%d", &data);
				q_insert(queue, MAX_QUEUE, &front, &rear, data);
				printf("Done\n");
				break;

			case (2):
				data = q_delete(queue, MAX_QUEUE, &front, &rear);
				printf("\nData = %d\n", data);
				break;

			default:
				exit(1);
				break;
		}
	}

	return 0;
}
