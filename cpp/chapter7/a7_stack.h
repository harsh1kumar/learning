/*
 * A generic Stack
 */

#ifndef A7_STACK_H
#define A7_STACK_H

class Stack
{
	class Node
	{

	public:
		void * data;
		Node * next;
		
		Node(void * in_data, Node * in_next);
		~Node();

	} * head;

public:

	Stack();
	Stack(void * arr[], int arr_size);
	~Stack();

	void push(void * in_data);
	void * pop();
	void * peek();
	bool is_empty();
};


#endif // A7_STACK_H
