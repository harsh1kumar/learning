
#include <stdio.h>

#include "06_mway_stree.h"

int main()
{
	struct mway_node * tree = NULL;
	int i;

	i = 18;
	printf("%d%s found in the tree\n", i, ( search_data(tree, i) == NULL ) ? " not" : "" );

	i = 44;
	tree = insert_data(tree, i); printf("\nInorder: "); inorder(tree); printf("\n");

	i = 18;
	tree = insert_data(tree, i); printf("\nInorder: "); inorder(tree); printf("\n");

	i = 76;
	tree = insert_data(tree, i); printf("\nInorder: "); inorder(tree); printf("\n");

	i = 198;
	tree = insert_data(tree, i); printf("\nInorder: "); inorder(tree); printf("\n");

	i = 6;
	tree = insert_data(tree, i); printf("\nInorder: "); inorder(tree); printf("\n");

	i = 262;
	tree = insert_data(tree, i); printf("\nInorder: "); inorder(tree); printf("\n");

	i = 7;
	tree = insert_data(tree, i); printf("\nInorder: "); inorder(tree); printf("\n");

	i = 12;
	tree = insert_data(tree, i); printf("\nInorder: "); inorder(tree); printf("\n");

	i = 80;
	tree = insert_data(tree, i); printf("\nInorder: "); inorder(tree); printf("\n");

	i = 92;
	tree = insert_data(tree, i); printf("\nInorder: "); inorder(tree); printf("\n");

	i = 141;
	tree = insert_data(tree, i); printf("\nInorder: "); inorder(tree); printf("\n");

	i = 13;
	tree = insert_data(tree, i); printf("\nInorder: "); inorder(tree); printf("\n");

	i = 142;
	tree = insert_data(tree, i); printf("\nInorder: "); inorder(tree); printf("\n");

	i = 263;
	tree = insert_data(tree, i); printf("\nInorder: "); inorder(tree); printf("\n");

	i = 264;
	tree = insert_data(tree, i); printf("\nInorder: "); inorder(tree); printf("\n");

	i = 265;
	tree = insert_data(tree, i); printf("\nInorder: "); inorder(tree); printf("\n");

	i = 8;
	tree = insert_data(tree, i); printf("\nInorder: "); inorder(tree); printf("\n");

	i = 10;
	tree = insert_data(tree, i); printf("\nInorder: "); inorder(tree); printf("\n");

	i = 77;
	tree = insert_data(tree, i); printf("\nInorder: "); inorder(tree); printf("\n");

	i = 148;
	tree = insert_data(tree, i); printf("\nInorder: "); inorder(tree); printf("\n");

	i = 151;
	tree = insert_data(tree, i); printf("\nInorder: "); inorder(tree); printf("\n");

	i = 172;
	tree = insert_data(tree, i); printf("\nInorder: "); inorder(tree); printf("\n");

	i = 186;
	tree = insert_data(tree, i); printf("\nInorder: "); inorder(tree); printf("\n");

	i = 272;
	tree = insert_data(tree, i); printf("\nInorder: "); inorder(tree); printf("\n");

	i = 286;
	tree = insert_data(tree, i); printf("\nInorder: "); inorder(tree); printf("\n");

	i = 350;
	tree = insert_data(tree, i); printf("\nInorder: "); inorder(tree); printf("\n");


	printf("\n--------------------------------------------------------------\n");

	i = 13;
	tree = delete_data(tree, i); printf("\nInorder: "); inorder(tree); printf("\n");

	i = 142;
	tree = delete_data(tree, i); printf("\nInorder: "); inorder(tree); printf("\n");

	i = 263;
	tree = delete_data(tree, i); printf("\nInorder: "); inorder(tree); printf("\n");

	i = 264;
	tree = delete_data(tree, i); printf("\nInorder: "); inorder(tree); printf("\n");

	i = 265;
	tree = delete_data(tree, i); printf("\nInorder: "); inorder(tree); printf("\n");

	printf("\n--------------------------------------------------------------\n");

	i = 150;
	tree = insert_data(tree, i); printf("\nInorder: "); inorder(tree); printf("\n");

	i = 149;
	tree = insert_data(tree, i); printf("\nInorder: "); inorder(tree); printf("\n");

	i = 18;
	tree = delete_data(tree, i); printf("\nInorder: "); inorder(tree); printf("\n");

	i = 76;
	tree = delete_data(tree, i); printf("\nInorder: "); inorder(tree); printf("\n");

	

	return 0;
}



