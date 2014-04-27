#ifndef H_13_CIR_QUEUE
#define H_13_CIR_QUEUE

struct queue_node
{
	int data;
	struct queue_node * next;
};

/* Only rear pointer is required as (front = rear->next) because it is a circular queue */
struct queue
{
	struct queue_node * rear;
};

void q_init(struct queue * q);
void q_insert(struct queue * q, int data);
int q_delete(struct queue * q);

#endif // H_13_CIR_QUEUE
