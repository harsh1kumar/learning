#include "16_priority_q.h"

#include <stdio.h>
#include <stdlib.h>

struct pq_node * pq_insert(struct pq_node * pq, int data, int priority)
{
	struct pq_node * new_node;
	struct pq_node * node;

	new_node = (struct pq_node *)malloc( sizeof(struct pq_node) );
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: Memory allocation failed while adding %d\n", data);
		exit(1);
	}
	new_node->data = data;
	new_node->priority = priority;

	if (pq == NULL)
	{
		new_node->next = NULL;
		pq = new_node;
		return pq;
	}

	if (pq->priority > priority)
	{
		new_node->next = pq;
		pq = new_node;
		return pq;
	}

	for (node = pq; node->next != NULL; node = node->next)
		if ( node->next->priority > priority )
			break;

	new_node->next = node->next;
	node->next = new_node;
	return pq;
}

 struct pq_node * pq_delete(struct pq_node * pq, int * pdata)
{
	struct pq_node * del_node;

	if (pq == NULL)
	{
		fprintf(stderr, "Error: Queue Underflow\n");
		exit(1);
	}

	del_node = pq;
	*pdata = pq->data;
	pq = pq->next;

	free(del_node);

	return pq;
}

void pq_print(struct pq_node * pq)
{
	printf("[Priority Q] : ");
	for ( ; pq != NULL; pq = pq->next)
		printf("(%d, %d) ", pq->data, pq->priority);
	printf("\n");
}
