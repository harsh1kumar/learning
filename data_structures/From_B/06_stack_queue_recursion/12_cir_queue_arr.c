/*
 * Circular queue implemented using an array
 */

#include "12_cir_queue_arr.h"

#include <stdio.h>
#include <stdlib.h>

void q_init(int * q, int max_size, int * pfront, int * prear)
{
	*pfront = *prear = -1;
}

void q_insert(int * q, int max_size, int * pfront, int * prear, int data)
{
	if ( q_is_full(q, max_size, pfront, prear) )
	{
		fprintf(stderr, "Error: Queue Overflow while adding %d\n", data);
		exit(1);
	}

	if ( *pfront == -1 && *prear == -1 )
		*pfront = *prear = 0;
	else if ( *prear == max_size-1 )
		*prear = 0;
	else
		++(*prear);

	q[*prear] = data;
}

int q_delete(int * q, int max_size, int * pfront, int * prear)
{
	int ret;

	if ( q_is_empty(q, max_size, pfront, prear) )
	{
		fprintf(stderr, "Error: Queue Underflow\n");
		exit(1);
	}

	ret = q[*pfront];

	if ( *pfront == *prear )
		*pfront = *prear = -1; /* Queue is empty now */
	else if (*pfront == max_size-1)
		*pfront = 0;
	else
		++(*pfront);

	return ret;
}

int q_is_empty(int * q, int max_size, int * pfront, int * prear)
{
	return (*pfront == -1 && *prear == -1);
}

int q_is_full(int * q, int max_size, int * pfront, int * prear)
{
	return (*pfront == 0 && *prear == max_size-1) || (*pfront == *prear + 1);
}

void q_print(int * q, int max_size, int * pfront, int * prear)
{
	int i;

	printf("[Queue] : ");
	if ( !q_is_empty(q, max_size, pfront, prear) )
	{
		for (i = *pfront; i != *prear; ++i)
			printf("%d ", q[i]);
		printf("%d", q[*prear]);
	}
	printf("\n");
}

