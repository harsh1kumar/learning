/*
 * Queue implementation using arrays
 */

#include "10_queue_arr.h"

#include <stdio.h>
#include <stdlib.h>

void q_init(int *pfront, int *prear)
{
	*pfront = -1;
	*prear = -1;
}

void q_insert(int * queue, int max_size, int * pfront, int * prear, int data)
{
	if ( (*pfront == 0 && *prear == max_size-1) || (*pfront == *prear+1))
	{
		fprintf(stderr, "Error: Queue Overflow while adding %d\n", data);
		exit(1);
	}

	if ( *prear == -1)
		*pfront = *prear = 0;
	else if (*prear == max_size-1)
		*prear = 0;
	else
		++(*prear);

	queue[*prear] = data;
}

int q_delete(int * queue, int max_size, int *pfront, int *prear)
{
	int retval;

	if ( *pfront == -1 )
	{
		fprintf(stderr, "Error: Queue Underflow\n");
		exit(1);
	}

	retval = queue[*pfront];
	if (*pfront == *prear)
		*pfront = *prear = -1;
	else if (*pfront == max_size-1)
		*pfront = 0;
	else
		++(*pfront);

	return retval;
}
