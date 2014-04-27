#include <stdio.h>

#include "12_cir_queue_arr.h"

#define MAX_Q 3

int main()
{
	int q[MAX_Q];
	int front;
	int rear;

	q_init(q, MAX_Q, &front, &rear); q_print(q, MAX_Q, &front, &rear);

	q_insert(q, MAX_Q, &front, &rear, 10); q_print(q, MAX_Q, &front, &rear);
	q_insert(q, MAX_Q, &front, &rear, 20); q_print(q, MAX_Q, &front, &rear);
	q_insert(q, MAX_Q, &front, &rear, 30); q_print(q, MAX_Q, &front, &rear);

	printf("Val = %d\n", q_delete(q, MAX_Q, &front, &rear));
	printf("Val = %d\n", q_delete(q, MAX_Q, &front, &rear));
	printf("Val = %d\n", q_delete(q, MAX_Q, &front, &rear));

	q_insert(q, MAX_Q, &front, &rear, 40); q_print(q, MAX_Q, &front, &rear);
	q_insert(q, MAX_Q, &front, &rear, 50); q_print(q, MAX_Q, &front, &rear);
	printf("Val = %d\n", q_delete(q, MAX_Q, &front, &rear));
	q_insert(q, MAX_Q, &front, &rear, 60); q_print(q, MAX_Q, &front, &rear);
	printf("Val = %d\n", q_delete(q, MAX_Q, &front, &rear));
	printf("Val = %d\n", q_delete(q, MAX_Q, &front, &rear));

	return 0;
}
