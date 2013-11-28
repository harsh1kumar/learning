/*
 * 
 */

#include "a7_stack.h"
#include <cassert>

using namespace std;

Stack::Node::Node(void * in_data, Node * in_next)
{
	data = in_data;
	next = in_next;
}

Stack::Node::~Node()
{
	
}

Stack::Stack()
{
	head = 0;
}

Stack::Stack(void * arr[], int arr_size)
{
	head = 0;
	for(int i =0; i < arr_size; ++i)
	{
		push(arr[i]);
	}
}

Stack::~Stack()
{
	assert(is_empty());
}

void Stack::push(void * in_data)
{
	Node * new_node = new Node(in_data, head);
	head = new_node;
}

void * Stack::pop()
{
	void * retval = head->data;
	Node * temp_node = head;
	head = head->next;
	delete temp_node;
	return retval;
}

void * Stack::peek()
{
	return head->data;
}

bool Stack::is_empty()
{
	return (head == 0);
}



