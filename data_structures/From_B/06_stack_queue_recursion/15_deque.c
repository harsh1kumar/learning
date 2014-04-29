/*
 * Deque: Double ended queue
 */

#include <stdio.h>
#include <stdlib.h>

#include "15_deque.h"

// void dq_insert(int * dq, int max_size, int * index, int data)

void dq_init(int * pleft, int * pright)
{
	*pleft = -1;
	*pright = -1;
}

void dq_insert_left(int * dq, int max_size, int * pleft, int * pright, int data)
{
	if (dq_is_full(max_size, *pleft, *pright))
	{
		fprintf(stderr, "Error: Deque Overflow while adding %d\n",data);
		exit(1);
	}

	if (*pleft == -1 && *pright == -1)
		*pleft = *pright = 0;
	else if (*pleft == 0)
		*pleft = max_size-1;
	else
		--(*pleft);

	dq[*pleft] = data;
}

void dq_insert_right(int * dq, int max_size, int * pleft, int * pright, int data)
{
	if (dq_is_full(max_size, *pleft, *pright))
	{
		fprintf(stderr, "Error: Deque Overflow while adding %d\n",data);
		exit(1);
	}

	if (*pleft == -1 && *pright == -1)
		*pleft = *pright = 0;
	else if (*pright == max_size-1)
		*pright = 0;
	else
		++(*pright);

	dq[*pright] = data;
}

int dq_remove_left(int * dq, int max_size, int * pleft, int * pright)
{
	int ret = dq[*pleft];

	if ( dq_is_empty(max_size, *pleft, *pright) )
	{
		fprintf(stderr, "Error: Deque Underflow\n");
		exit(1);
	}

	if ( *pleft == *pright )
		*pleft = *pright = -1; /* dq is empty now*/
	else if (*pleft == max_size-1)
		*pleft = 0;
	else
		++(*pleft);

	return ret;
}

int dq_remove_right(int * dq, int max_size, int * pleft, int * pright)
{
	int ret = dq[*pright];

	if ( dq_is_empty(max_size, *pleft, *pright) )
	{
		fprintf(stderr, "Error: Deque Underflow\n");
		exit(1);
	}

	if ( *pleft == *pright )
		*pleft = *pright = -1; /* dq is empty now*/
	else if (*pright == 0)
		*pright = max_size-1;
	else
		--(*pright);

	return ret;
}

int dq_is_full(int max_size, int left, int right)
{
	return ((left == 0 && right == max_size-1) || (left == right+1));
}

int dq_is_empty(int max_size, int left, int right)
{
	return (left == -1 && right == -1);
}

void dq_print(int * dq, int max_size, int left, int right)
{
	int i;

	printf("[Deque] : ");
	if ( !dq_is_empty(max_size, left, right))
	{
		i = left;
		do
		{
			if ( i == max_size )
				i=0;
			printf("%d ", dq[i]);
			++i;
		} while ( i != right+1 );
	}
	printf("\n");
}



