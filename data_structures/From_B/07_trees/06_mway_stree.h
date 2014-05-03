/*
 * M-Way search tree
 */

#ifndef H_06_MWAY_STREE
#define H_06_MWAY_STREE

#define MWAY_ORDER 5

struct mway_node
{
	int data[MWAY_ORDER-1];
	struct mway_node * links[MWAY_ORDER];
	int num_data; /* Number of data elements */
};


struct mway_node * search_data(struct mway_node * tree, int data);

struct mway_node * insert_data(struct mway_node * tree, int data);

struct mway_node * delete_data(struct mway_node * tree, int data);

void inorder(struct mway_node * tree);

#endif // H_06_MWAY_STREE



