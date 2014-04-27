/*
 * Queue implementation using structs
 */

#include "11_queue.h"

#include <stdio.h>
#include <stdlib.h>

void q_init(struct queue * q)
{
	q->front = NULL;
	q->rear = NULL;
}

void q_insert(struct queue * q, void * data)
{
	struct queue_node * new_node;
	new_node = (struct queue_node *) malloc( sizeof(struct queue_node) );
	if ( new_node == NULL )
	{
		fprintf(stderr, "Error: Memory allocation failed while inserting in queue\n");
		exit(1);
	}

	new_node->data = data;
	new_node->next = NULL;

	if ( q->front == NULL)
		q->front = new_node;
	else
		q->rear->next = new_node;

	q->rear = new_node;
}

void * q_delete(struct queue * q)
{
	void * ret;
	struct queue_node * node;

	if (q->front == NULL)
	{
		fprintf(stderr, "Error: Queue Underflow\n");
		exit(1);
	}

	node = q->front;
	ret = node->data;
	q->front = node->next;
	if (q->front == NULL)
		q->rear = NULL;

	free(node);

	return ret;
}

