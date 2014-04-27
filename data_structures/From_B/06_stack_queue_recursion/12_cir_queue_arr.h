#ifndef H_12_CIRQ 
#define H_12_CIRQ

void q_init(int * q, int max_size, int * pfront, int * prear);
void q_insert(int * q, int max_size, int * pfront, int * prear, int data);
int q_delete(int * q, int max_size, int * pfront, int * prear);
int q_is_empty(int * q, int max_size, int * pfront, int * prear);
int q_is_full(int * q, int max_size, int * pfront, int * prear);
void q_print(int * q, int max_size, int * pfront, int * prear);

#endif // H_12_CIRQ
