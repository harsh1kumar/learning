/*
 * Circular queue
 */

#include "13_cir_queue.h"

#include <stdio.h>
#include <stdlib.h>

void q_init(struct queue * q)
{
	q->rear = NULL;
}

void q_insert(struct queue * q, int data)
{
	struct queue_node * new_node;

	new_node = (struct queue_node *)malloc( sizeof(struct queue_node) );
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: Memory allocation failed while adding %d\n", data);
		exit(1);
	}
	new_node->data = data;

	if (q->rear == NULL)
	{
		/* Empty queue */
		new_node->next = new_node;
		q->rear = new_node;
	}
	else
	{
		new_node->next = q->rear->next;
		q->rear->next = new_node;
		q->rear = new_node;
	}
}

int q_delete(struct queue * q)
{
	struct queue_node * del_node;
	int ret;

	if (q->rear == NULL)
	{
		fprintf(stderr, "Error: Queue Underflow\n");
		exit(1);
	}

	del_node = q->rear->next;

	if (q->rear->next == q->rear)
		q->rear = NULL;
	else
		q->rear->next = del_node->next;

	ret = del_node->data;
	free(del_node);

	return ret;
}


