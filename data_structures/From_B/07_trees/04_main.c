#include <stdio.h>
#include <stdlib.h>

#include "04_bs_tree.h"

int main()
{
	struct tree_node * tree = NULL;

	print_tree(tree);

	/* Adding root */
	tree = insert_node(tree, 18); print_tree(tree);
	tree = insert_node(tree, 14); print_tree(tree);
	tree = insert_node(tree, 24); print_tree(tree);
	tree = insert_node(tree, 12); print_tree(tree);
	tree = insert_node(tree, 16); print_tree(tree);
	tree = insert_node(tree, 22); print_tree(tree);
	tree = insert_node(tree, 29); print_tree(tree);
	tree = insert_node(tree, 15); print_tree(tree);
	tree = insert_node(tree, 26); print_tree(tree);
	tree = insert_node(tree, 30); print_tree(tree);
	tree = insert_node(tree, 25); print_tree(tree);
	tree = insert_node(tree, 27); print_tree(tree);

#if 0
	/* Tests 1*/
	tree = delete_node(tree, 22); print_tree(tree);
	tree = delete_node(tree, 29); print_tree(tree);
	tree = delete_node(tree, 14); print_tree(tree);
	tree = delete_node(tree, 18); print_tree(tree);
	tree = delete_node(tree, 24); print_tree(tree);
	tree = delete_node(tree, 25); print_tree(tree);
	tree = delete_node(tree, 27); print_tree(tree);
	tree = delete_node(tree, 26); print_tree(tree);
	tree = delete_node(tree, 30); print_tree(tree);
	tree = delete_node(tree, 15); print_tree(tree);
	tree = delete_node(tree, 16); print_tree(tree);
	tree = delete_node(tree, 12); print_tree(tree);
#else
	/* Tests 2 */
	tree = delete_node(tree, 14); print_tree(tree);
	tree = delete_node(tree, 16); print_tree(tree);
	tree = delete_node(tree, 15); print_tree(tree);
	tree = delete_node(tree, 12); print_tree(tree);
	tree = delete_node(tree, 18); print_tree(tree);
	tree = delete_node(tree, 24); print_tree(tree);
	tree = delete_node(tree, 25); print_tree(tree);
	tree = delete_node(tree, 26); print_tree(tree);
	tree = delete_node(tree, 27); print_tree(tree);
	tree = delete_node(tree, 29); print_tree(tree);
	tree = delete_node(tree, 30); print_tree(tree);
	tree = delete_node(tree, 22); print_tree(tree);
#endif
	return 0;
}



