#ifndef H_03_STACK_LL
#define H_03_STACK_LL

typedef enum bool_t {TRUE, FALSE} Bool;

struct stack_node
{
	void * data;
	struct stack_node * next;
};

void push(struct stack_node ** ptop, void * data);
void * pop(struct stack_node ** ptop);
Bool is_empty(const struct stack_node * top);
Bool is_full(const struct stack_node * top);

#endif // H_03_STACK_LL
