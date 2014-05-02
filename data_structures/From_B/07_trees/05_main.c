#include <stdio.h>

#include "05_avl_stree.h"

int main()
{
	struct tree_node * tree = NULL;
	
	print_tree(tree);

#if 0
	/* Test LL Rot */
	tree = insert_node(tree, 96); print_tree(tree);
	tree = insert_node(tree, 85); print_tree(tree);
	tree = insert_node(tree, 110); print_tree(tree);
	tree = insert_node(tree, 64); print_tree(tree);
	tree = insert_node(tree, 90); print_tree(tree);
	tree = insert_node(tree, 36); print_tree(tree);

#elif 0
	/* Test RR Rot */
	tree = insert_node(tree, 34); print_tree(tree);
	tree = insert_node(tree, 26); print_tree(tree);
	tree = insert_node(tree, 44); print_tree(tree);
	tree = insert_node(tree, 40); print_tree(tree);
	tree = insert_node(tree, 56); print_tree(tree);
	tree = insert_node(tree, 65); print_tree(tree);

#elif 0
	/* Test LR Rot */
	tree = insert_node(tree, 44); print_tree(tree);
	tree = insert_node(tree, 30); print_tree(tree);
	tree = insert_node(tree, 76); print_tree(tree);
	tree = insert_node(tree, 16); print_tree(tree);
	tree = insert_node(tree, 39); print_tree(tree);
	tree = insert_node(tree, 37); print_tree(tree);

#elif 0
	/* Test More */
	tree = insert_node(tree, 64); print_tree(tree);
	tree = insert_node(tree, 1); print_tree(tree);
	tree = insert_node(tree, 14); print_tree(tree);
	tree = insert_node(tree, 26); print_tree(tree);
	tree = insert_node(tree, 13); print_tree(tree);
	tree = insert_node(tree, 110); print_tree(tree);
	tree = insert_node(tree, 98); print_tree(tree);
	tree = insert_node(tree, 85); print_tree(tree);

#elif 0
	/* Test delete 1 */
	tree = insert_node(tree, 46); print_tree(tree);
	tree = insert_node(tree, 20); print_tree(tree);
	tree = insert_node(tree, 54); print_tree(tree);
	tree = insert_node(tree, 18); print_tree(tree);
	tree = insert_node(tree, 23); print_tree(tree);
	tree = insert_node(tree, 60); print_tree(tree);
	tree = insert_node(tree, 7); print_tree(tree);
	tree = insert_node(tree, 24); print_tree(tree);
	tree = delete_node(tree, 60); print_tree(tree);

#elif 0
	/* Test delete 1 */
	tree = insert_node(tree, 37); print_tree(tree);
	tree = insert_node(tree, 26); print_tree(tree);
	tree = insert_node(tree, 41); print_tree(tree);
	tree = insert_node(tree, 18); print_tree(tree);
	tree = insert_node(tree, 28); print_tree(tree);
	tree = insert_node(tree, 39); print_tree(tree);
	tree = insert_node(tree, 16); print_tree(tree);
	tree = delete_node(tree, 39); print_tree(tree);

#elif 1
	/* Test delete 1 */
	tree = insert_node(tree, 44); print_tree(tree);
	tree = insert_node(tree, 22); print_tree(tree);
	tree = insert_node(tree, 48); print_tree(tree);
	tree = insert_node(tree, 18); print_tree(tree);
	tree = insert_node(tree, 28); print_tree(tree);
	tree = insert_node(tree, 52); print_tree(tree);
	tree = insert_node(tree, 23); print_tree(tree);
	tree = insert_node(tree, 29); print_tree(tree);
	tree = delete_node(tree, 52); print_tree(tree);

#endif

	return 0;
}

