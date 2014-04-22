#ifndef H_02_SLL_ARR
#define H_02_SLL_ARR

typedef void (*process_func_t)(int);

void init_ll(int data);
void print_ll();
void traverse_ll(process_func_t process);
int search_ll(int data);
void insert_data(int data);
void delete_data(int data);

#endif // H_01_LL_ARRAY_H
