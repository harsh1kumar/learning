#ifndef H_16_PRIORITY_Q 
#define H_16_PRIORITY_Q

struct pq_node
{
	int data;
	int priority;
	struct pq_node * next;
};

struct pq_node * pq_insert(struct pq_node * pq, int data, int priority);
struct pq_node * pq_delete(struct pq_node * pq, int * pdata);
void pq_print(struct pq_node * pq);

#endif // H_16_PRIORITY_Q
