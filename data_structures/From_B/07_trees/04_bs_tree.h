/*
 * Binary Seach Tree
 */

#ifndef H_04_BSTREE
#define H_04_BSTREE

struct tree_node
{
	int data;
	struct tree_node * left;
	struct tree_node * right;
};

/* 
 * Returns the pointer to the node with data, NULL otherwise. 
 *	parent will have the pointer of parent of node having data.
 *	parent will be NULL if data is found at root of tree.
 */
struct tree_node * find(struct tree_node * tree, int data, struct tree_node ** parent);

/* Returns the pointer to modified parent */
struct tree_node * insert_node(struct tree_node * tree, int data);

/* Returns pointer to modified parent */
struct tree_node * delete_node(struct tree_node * tree, int data);

void print_tree(struct tree_node * tree);

#endif // H_04_BSTREE

