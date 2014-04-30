/*
 * Priority Queue implemented using a 2d array where each row serves as a circular queue
 */

#include "17_prior_q_2arr.h"

#include <stdio.h>
#include <stdlib.h>

/* Private functions */
static int q_is_full(int max, int front, int rear);
static int q_is_empty(int max, int front, int rear);



void pq_init(int max_prior, int * front, int * rear)
{
	while (max_prior--)
		*(front++) = *(rear++) = -1;
}

void pq_insert(int pq[][Q_SIZE], int max_prior, int * front, int * rear, int data, int prior)
{
	if (prior < 0 || prior > max_prior-1)
	{
		fprintf(stderr, "Error: prior should be >= 0 && <= %d\n", max_prior-1);
		exit(1);
	}

	if ( q_is_full(Q_SIZE, front[prior], rear[prior]) )
	{
		fprintf(stderr, "Error: Queue Overflow while adding %d with prior %d\n", data, prior);
		exit(1);
	}

	if (front[prior] == -1 && rear[prior] == -1)
		front[prior] = rear[prior] = 0;
	else if (rear[prior] == Q_SIZE-1)
		rear[prior] = 0;
	else
		++rear[prior];

	pq[prior][rear[prior]] = data;
}

int pq_delete(int pq[][Q_SIZE], int max_prior, int * front, int * rear)
{
	int i;
	int retval;

	for (i=0; i<max_prior; ++i)
		if ( !q_is_empty(Q_SIZE, front[i], rear[i]) )
			break;

	if ( i==max_prior )
	{
		fprintf(stderr, "Error: Queue Underflow\n");
		exit(1);
	}

	retval = pq[i][front[i]];

	if ( front[i] == rear[i] )
		front[i] = rear[i] = -1;
	else if ( front[i] == max_prior-1 )
		front[i] = 0;
	else
		++front[i];

	return retval;
}

static int q_is_full(int max, int front, int rear)
{
	return (front == 0 && rear == max-1) || (front == rear+1);
}

static int q_is_empty(int max, int front, int rear)
{
	return (front == -1 && rear == -1);
}

