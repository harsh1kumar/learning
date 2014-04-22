#ifndef H_03_LL 
#define H_03_LL

typedef void (*process_func_t)(int);

void insert_at_begin(int data);
void insert_after_d(int d, int data);
void insert_at_end(int data);
void delete_data(int data);
void print_ll(void);
void traverse_ll(process_func_t process);
void * search_ll(int data);

#endif // H_03_LL
