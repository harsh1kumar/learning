#ifndef H_01_LL_ARRAY_H
#define H_01_LL_ARRAY_H

typedef void (*process_func_t)(int);

void init_ll(int data);
void print_ll();
void traverse_ll(process_func_t process);
int search_ll(int data);
void insert_at_end(int data);
void insert_at_begin(int data);
void insert_after_d(int d, int data);
void delete_data(int data);

#endif // H_01_LL_ARRAY_H
