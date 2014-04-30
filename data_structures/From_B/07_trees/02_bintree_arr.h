/*
 * Binary tree implemented as a sequential array
 *
 * 	If index of parent is K, index of children will be 2K+1 & 2K+2
 * 	NULL tree will be denoted by -1 i.e tree can contain only positive values
 * 	User has to supply the array for the tree
 */

#ifndef H_02_BINTREE_ARR
#define H_02_BINTREE_ARR

void preorder(int * tree, int root);
void inorder(int * tree, int root);
void postorder(int * tree, int root);

/* Non- recursive traversal functions implemented using stack */
void preorder_stack(int * tree, int root);
void inorder_stack(int * tree, int root);
void postorder_stack(int * tree, int root);

 #endif // H_02_BINTREE_ARR
