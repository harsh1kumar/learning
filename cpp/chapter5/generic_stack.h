/*
 * A generic Stack
 */

#ifndef GENERIC_STACK_H
#define GENERIC_STACK_H

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
	~Stack();

	void push(void * in_data);
	void * pop();
	void * peek();
	bool is_empty();
};


#endif // GENERIC_STACK_H
