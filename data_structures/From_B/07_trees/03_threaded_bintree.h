/*
 * Threaded binary tree - Inorder one-way threading
 */

#ifndef H_03_THREADED_BINTREE
#define H_03_THREADED_BINTREE

typedef enum {NO_THREAD, THREAD} thread_t;

struct tt_node
{
	int data;
	struct tt_node * left;
	struct tt_node * right;
	thread_t rthread;
};

void tt_inorder(struct tt_node * tree);
struct tt_node * tt_insert(struct tt_node * node, int data, int left);

#endif // H_03_THREADED_BINTREE
