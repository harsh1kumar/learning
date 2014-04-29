#include <stdio.h>

#include "15_deque.h" 

#define MAX_DQ 10

int main()
{
	int dq[MAX_DQ];
	int left;
	int right;
	int i;

	dq_init(&left, &right); dq_print(dq, MAX_DQ, left, right);

	dq_insert_left(dq, MAX_DQ, &left, &right, 30); dq_print(dq, MAX_DQ, left, right);
	dq_insert_right(dq, MAX_DQ, &left, &right, 40); dq_print(dq, MAX_DQ, left, right);
	dq_insert_left(dq, MAX_DQ, &left, &right, 20); dq_print(dq, MAX_DQ, left, right);
	dq_insert_left(dq, MAX_DQ, &left, &right, 10); dq_print(dq, MAX_DQ, left, right);
	dq_insert_right(dq, MAX_DQ, &left, &right, 50); dq_print(dq, MAX_DQ, left, right);
	dq_insert_right(dq, MAX_DQ, &left, &right, 60); dq_print(dq, MAX_DQ, left, right);
	dq_insert_right(dq, MAX_DQ, &left, &right, 70); dq_print(dq, MAX_DQ, left, right);
	dq_insert_right(dq, MAX_DQ, &left, &right, 80); dq_print(dq, MAX_DQ, left, right);
	dq_insert_right(dq, MAX_DQ, &left, &right, 90); dq_print(dq, MAX_DQ, left, right);
	dq_insert_right(dq, MAX_DQ, &left, &right, 100); dq_print(dq, MAX_DQ, left, right);

	printf("\nLeft = %d\n", dq_remove_left(dq, MAX_DQ, &left, &right));
	printf("Right = %d\n", dq_remove_right(dq, MAX_DQ, &left, &right));
	printf("Left = %d\n", dq_remove_left(dq, MAX_DQ, &left, &right));
	printf("Right = %d\n", dq_remove_right(dq, MAX_DQ, &left, &right));
	printf("Left = %d\n", dq_remove_left(dq, MAX_DQ, &left, &right));
	printf("Right = %d\n", dq_remove_right(dq, MAX_DQ, &left, &right));
	printf("Left = %d\n", dq_remove_left(dq, MAX_DQ, &left, &right));
	printf("Right = %d\n", dq_remove_right(dq, MAX_DQ, &left, &right));
	printf("Left = %d\n", dq_remove_left(dq, MAX_DQ, &left, &right));
	printf("Right = %d\n\n", dq_remove_right(dq, MAX_DQ, &left, &right));

	dq_insert_left(dq, MAX_DQ, &left, &right, 10); dq_print(dq, MAX_DQ, left, right);
	dq_insert_left(dq, MAX_DQ, &left, &right, 20); dq_print(dq, MAX_DQ, left, right);
	dq_insert_left(dq, MAX_DQ, &left, &right, 30); dq_print(dq, MAX_DQ, left, right);
	dq_insert_left(dq, MAX_DQ, &left, &right, 40); dq_print(dq, MAX_DQ, left, right);
	dq_insert_left(dq, MAX_DQ, &left, &right, 50); dq_print(dq, MAX_DQ, left, right);
	dq_insert_left(dq, MAX_DQ, &left, &right, 60); dq_print(dq, MAX_DQ, left, right);
	dq_insert_left(dq, MAX_DQ, &left, &right, 70); dq_print(dq, MAX_DQ, left, right);
	dq_insert_left(dq, MAX_DQ, &left, &right, 80); dq_print(dq, MAX_DQ, left, right);
	dq_insert_left(dq, MAX_DQ, &left, &right, 90); dq_print(dq, MAX_DQ, left, right);
	dq_insert_left(dq, MAX_DQ, &left, &right, 100); dq_print(dq, MAX_DQ, left, right);

	printf("\nValues right to left: ");
	for (i=0; i<MAX_DQ; ++i)
		printf("%d ", dq_remove_right(dq, MAX_DQ, &left, &right));
	printf("\n\n");

	dq_insert_right(dq, MAX_DQ, &left, &right, 10); dq_print(dq, MAX_DQ, left, right);
	dq_insert_right(dq, MAX_DQ, &left, &right, 20); dq_print(dq, MAX_DQ, left, right);
	dq_insert_right(dq, MAX_DQ, &left, &right, 30); dq_print(dq, MAX_DQ, left, right);
	dq_insert_right(dq, MAX_DQ, &left, &right, 40); dq_print(dq, MAX_DQ, left, right);
	dq_insert_right(dq, MAX_DQ, &left, &right, 50); dq_print(dq, MAX_DQ, left, right);
	dq_insert_right(dq, MAX_DQ, &left, &right, 60); dq_print(dq, MAX_DQ, left, right);
	dq_insert_right(dq, MAX_DQ, &left, &right, 70); dq_print(dq, MAX_DQ, left, right);
	dq_insert_right(dq, MAX_DQ, &left, &right, 80); dq_print(dq, MAX_DQ, left, right);
	dq_insert_right(dq, MAX_DQ, &left, &right, 90); dq_print(dq, MAX_DQ, left, right);
	dq_insert_right(dq, MAX_DQ, &left, &right, 100); dq_print(dq, MAX_DQ, left, right);

	printf("\nValues left to right: ");
	for (i=0; i<MAX_DQ; ++i)
		printf("%d ", dq_remove_left(dq, MAX_DQ, &left, &right));
	printf("\n\n");

	return 0;
}
