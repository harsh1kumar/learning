#ifndef H_04_SLL
#define H_04_SLL

typedef void (*process_func_t)(int);

void print_ll();
void traverse_ll(process_func_t process);
void * search_ll(int data);
void insert_data(int data);
void delete_data(int data);

#endif // H_04_SLL
