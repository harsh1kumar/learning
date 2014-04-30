/*
 * Binary tree implemented using linked array
 *
 *	User has to supply 
 *		3 arrays: data, left, right all of same dimension
 *		tree: index of root of tree
 *		avail: index of the first free space in the arrays
 */

#ifndef H_01_BINTREE_LINKARR
#define H_01_BINTREE_LINKARR

void preorder(int * data, int * left, int * right, int tree);
void inorder(int * data, int * left, int * right, int tree);
void postorder(int * data, int * left, int * right, int tree);

/* Non- recursive traversal functions implemented using stack */
void preorder_stack(int * data, int * left, int * right, int tree);
void inorder_stack(int * data, int * left, int * right, int tree);
void postorder_stack(int * data, int * left, int * right, int tree);

#endif // H_01_BINTREE_LINKARR
