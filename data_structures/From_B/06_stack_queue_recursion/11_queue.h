#ifndef H_11_QUEUE 
#define H_11_QUEUE

struct queue_node
{
	void * data;
	struct queue_node * next;
};

struct queue
{
	struct queue_node * front;
	struct queue_node * rear;
};

void q_init(struct queue * q);
void q_insert(struct queue * q, void * data);
void * q_delete(struct queue * q);

#endif // H_11_QUEUE
