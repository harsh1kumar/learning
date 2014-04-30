#include <stdio.h> 

#include "17_prior_q_2arr.h"

#define MAX_PRIOR 4

int main()
{
	int pq[MAX_PRIOR][Q_SIZE];
	int front[MAX_PRIOR];
	int rear[MAX_PRIOR];
	int i;

	pq_init(MAX_PRIOR, front, rear);

	for (i=0; i < MAX_PRIOR; ++i)
		printf("%d %d\n", front[i], rear[i]);

	pq_insert(pq, MAX_PRIOR, front, rear, 21, 2);
	pq_insert(pq, MAX_PRIOR, front, rear, 11, 1);
	pq_insert(pq, MAX_PRIOR, front, rear, 31, 3);
	pq_insert(pq, MAX_PRIOR, front, rear, 01, 0);
	pq_insert(pq, MAX_PRIOR, front, rear, 02, 0);
	pq_insert(pq, MAX_PRIOR, front, rear, 03, 0);
	pq_insert(pq, MAX_PRIOR, front, rear, 10, 1);
	pq_insert(pq, MAX_PRIOR, front, rear, 20, 2);
	pq_insert(pq, MAX_PRIOR, front, rear, 30, 3);
	pq_insert(pq, MAX_PRIOR, front, rear, 29, 3);

	printf("Val = %d\n", pq_delete(pq, MAX_PRIOR, front, rear));
	printf("Val = %d\n", pq_delete(pq, MAX_PRIOR, front, rear));
	printf("Val = %d\n", pq_delete(pq, MAX_PRIOR, front, rear));
	printf("Val = %d\n", pq_delete(pq, MAX_PRIOR, front, rear));
	printf("Val = %d\n", pq_delete(pq, MAX_PRIOR, front, rear));
	printf("Val = %d\n", pq_delete(pq, MAX_PRIOR, front, rear));
	printf("Val = %d\n", pq_delete(pq, MAX_PRIOR, front, rear));
	printf("Val = %d\n", pq_delete(pq, MAX_PRIOR, front, rear));
	printf("Val = %d\n", pq_delete(pq, MAX_PRIOR, front, rear));
	printf("Val = %d\n", pq_delete(pq, MAX_PRIOR, front, rear));
	return 0;
}
