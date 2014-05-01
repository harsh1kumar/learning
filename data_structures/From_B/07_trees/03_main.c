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

#include "03_threaded_bintree.h"

int main()
{
	struct tt_node * tree = NULL;

	printf("[Inorder] : "); tt_inorder(tree); printf("\n");

	tree = tt_insert(tree, 'A', 1);
	printf("[Inorder] : "); tt_inorder(tree); printf("\n");

	tt_insert(tree, 'B', 1);
	printf("[Inorder] : "); tt_inorder(tree); printf("\n");

	tt_insert(tree, 'C', 0);
	printf("[Inorder] : "); tt_inorder(tree); printf("\n");

	tt_insert(tree->left, 'D', 1);
	printf("[Inorder] : "); tt_inorder(tree); printf("\n");

	tt_insert(tree->left, 'E', 0);
	printf("[Inorder] : "); tt_inorder(tree); printf("\n");

	tt_insert(tree->left->right, 'F', 1);
	printf("[Inorder] : "); tt_inorder(tree); printf("\n");

	tt_insert(tree->right, 'G', 1);
	printf("[Inorder] : "); tt_inorder(tree); printf("\n");

	tt_insert(tree->right, 'H', 0);
	printf("[Inorder] : "); tt_inorder(tree); printf("\n");

	tt_insert(tree->right->right, 'J', 1);
	printf("[Inorder] : "); tt_inorder(tree); printf("\n");

	tt_insert(tree->right->right, 'K', 0);
	printf("[Inorder] : "); tt_inorder(tree); printf("\n");

	tt_insert(tree->right->right->left, 'L', 1);
	printf("[Inorder] : "); tt_inorder(tree); printf("\n");

	return 0;
}

