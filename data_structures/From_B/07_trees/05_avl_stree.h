/*
 * AVL Seach Tree
 */

#ifndef H_05_AVL_STREE
#define H_05_AVL_STREE

struct tree_node
{
	int data;
	struct tree_node * left;
	struct tree_node * right;
	int height;
};

/* Returns the pointer to the node containing data or NULL if not found.
 * parent will contain pointer to the parent node. parent is NULL if data is found in root of the tree
 */
struct tree_node * find_data(struct tree_node * tree, int data, struct tree_node ** parent);
struct tree_node * insert_node(struct tree_node * tree, int data);
struct tree_node * delete_node(struct tree_node * tree, int data);
void print_tree(struct tree_node * tree);


#endif // H_05_AVL_STREE


