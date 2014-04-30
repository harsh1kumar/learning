/*
 * Arrangement of tree in the memory:
 *
 *	IDX	data	left	right
 *	----------------------------
 *	0	K	-1	-1
 *	1	C	2	5
 *	2	G	-1	-1
 *	3	-	13	-
 *	4	A	9	1
 *	5	H	16	0
 *	6	L	-1	-1
 *	7	-	8	-
 *	8	-	3	-
 *	9	B	17	12
 *	10	-	18	-
 *	11	F	-1	-1
 *	12	E	11	-1
 *	13	-	14	-
 *	14	-	15	-
 *	15	-	10	-
 *	16	J	6	-1
 *	17	D	-1	-1
 *	18	-	19	-
 *	19	-	-1	-
 *	
 *	tree = 4
 *	avail = 7
 *	 
 *	       _ A
 *	      /    \
 *	     B      C
 *	    / \    / \
 *	   D   E  G   H
 *	      /      / \
 *	     F      J   K
 *	           /
 *	          L
 *	
 */

#include <stdio.h>
#include "01_bintree_linkarr.h"

#define ARR_SIZE 20


int main()
{
	int data[ARR_SIZE];
	int left[ARR_SIZE];
	int right[ARR_SIZE];

	int tree;
	int avail;

	/* Populating Tree */
	data[0] = 'K'; left[0] = -1; right[0] = -1;
	data[1] = 'C'; left[1] = 2; right[1] = 5;
	data[2] = 'G'; left[2] = -1; right[2] = -1;
	data[4] = 'A'; left[4] = 9; right[4] = 1;
	data[5] = 'H'; left[5] = 16; right[5] = 0;
	data[6] = 'L'; left[6] = -1; right[6] = -1;
	data[9] = 'B'; left[9] = 17; right[9] = 12;
	data[11] = 'F'; left[11] = -1; right[11] = -1;
	data[12] = 'E'; left[12] = 11; right[12] = -1;
	data[16] = 'J'; left[16] = 6; right[16] = -1;
	data[17] = 'D'; left[17] = -1; right[17] = -1;

	/* Setting left index for free space */
	left[3] = 13;
	left[7] = 8;
	left[8] = 3;
	left[10] = 18;
	left[13] = 14;
	left[14] = 15;
	left[15] = 10;
	left[18] = 19;
	left[19] = -1;

	/*Setting correct index/pointers to tree & avail */
	tree = 4;
	avail = 7;

	printf("Preorder:  ");
	preorder(data, left, right, tree);
	printf("\n");

	printf("Preorder:  ");
	preorder_stack(data, left, right, tree);
	printf("\n");

	printf("Inorder:   ");
	inorder(data, left, right, tree);
	printf("\n");

	printf("Inorder:   ");
	inorder_stack(data, left, right, tree);
	printf("\n");

	printf("Postorder: ");
	postorder(data, left, right, tree);
	printf("\n");

	printf("Postorder: ");
	postorder_stack(data, left, right, tree);
	printf("\n");

	return 0;
}

