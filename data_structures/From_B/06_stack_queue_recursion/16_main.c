#include <stdio.h> 

#include "16_priority_q.h"

int main()
{
	struct pq_node * pq = NULL;
	int data;

	pq = pq_insert(pq, 10, 2); pq_print(pq);
	pq = pq_insert(pq, 10, 1); pq_print(pq);
	pq = pq_insert(pq, 10, 3); pq_print(pq);
	pq = pq_insert(pq, 10, 0); pq_print(pq);
	pq = pq_insert(pq, 20, 1); pq_print(pq);
	pq = pq_insert(pq, 15, 1); pq_print(pq);
	pq = pq_insert(pq, 15, 3); pq_print(pq);
	pq = pq_insert(pq, 15, 0); pq_print(pq);
	pq = pq_insert(pq, 15, 2); pq_print(pq);

	pq = pq_delete(pq, &data); printf("Process: %d\n", data);
	pq = pq_delete(pq, &data); printf("Process: %d\n", data);
	pq = pq_delete(pq, &data); printf("Process: %d\n", data);
	pq = pq_delete(pq, &data); printf("Process: %d\n", data);
	pq = pq_delete(pq, &data); printf("Process: %d\n", data);
	pq = pq_delete(pq, &data); printf("Process: %d\n", data);
	pq = pq_delete(pq, &data); printf("Process: %d\n", data);
	pq = pq_delete(pq, &data); printf("Process: %d\n", data);
	pq = pq_delete(pq, &data); printf("Process: %d\n", data);
	pq = pq_delete(pq, &data); printf("Process: %d\n", data);
	

	return 0;
}
