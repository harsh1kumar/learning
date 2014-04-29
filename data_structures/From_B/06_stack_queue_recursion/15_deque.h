#ifndef H_15_DEQUE
#define H_15_DEQUE

void dq_init(int * pleft, int * pright);
void dq_insert_left(int * dq, int max_size, int * pleft, int * pright, int data);
void dq_insert_right(int * dq, int max_size, int * pleft, int * pright, int data);
int dq_remove_left(int * dq, int max_size, int * pleft, int * pright);
int dq_remove_right(int * dq, int max_size, int * pleft, int * pright);
int dq_is_full(int max_size, int left, int right);
int dq_is_empty(int max_size, int left, int right);
void dq_print(int * dq, int max_size, int left, int right);

#endif // H_15_DEQUE
