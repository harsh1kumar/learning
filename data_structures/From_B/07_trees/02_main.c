/*
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

#include "02_bintree_arr.h"

#define MAX_ARR 63 /* Tree can upto a depth of 6 */

int main()
{
	int tree[MAX_ARR];
	int i;

	/* Populating the tree */
	for (i=0; i<MAX_ARR; ++i)
		tree[i] = -1;

	tree[0] = 'A';
	tree[1] = 'B';
	tree[2] = 'C';
	tree[3] = 'D';
	tree[4] = 'E';
	tree[5] = 'G';
	tree[6] = 'H';
	tree[9] = 'F';
	tree[13] = 'J';
	tree[14] = 'K';
	tree[27] = 'L';

	printf("Preorder:  ");
	preorder(tree, 0);
	printf("\n");

	printf("Preorder:  ");
	preorder_stack(tree, 0);
	printf("\n");

	printf("Inorder:   ");
	inorder(tree, 0);
	printf("\n");

	printf("Inorder:   ");
	inorder_stack(tree, 0);
	printf("\n");

	printf("Postorder: ");
	postorder(tree, 0);
	printf("\n");

	printf("Postorder: ");
	postorder_stack(tree, 0);
	printf("\n");

	return 0;
}

