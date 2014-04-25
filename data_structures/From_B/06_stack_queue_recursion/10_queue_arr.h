#ifndef H_10_QUEUE_ARR
#define H_10_QUEUE_ARR

void q_init(int *pfront, int *prear);
void q_insert(int * queue, int max_size, int * pfront, int * prear, int data);
int q_delete(int * queue, int max_size, int *pfront, int *prear);

#endif // H_10_QUEUE_ARR
