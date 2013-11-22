/*
 * Implementation of stack as a linked list
 */

#include <iostream>
#include "a8_stack_ll.h"

using namespace std;

inline void Stack::Node::init(double in_data, Node * in_next)
{
	data = in_data;
	next = in_next;

	return;
}

inline void Stack::Node::destruct()
{
	return;
}

inline double Stack::Node::get_data()
{
	return data;
}

inline Stack::Node * Stack::Node::get_next()
{
	return next;
}

void Stack::initialize()
{
	head = NULL;
	return;
}

void Stack::clear_stack()
{
	while(!is_empty())
		pop();

	return;
}

void Stack::push(double val)
{
	Node * new_node = new Node;

	new_node->init(val, head);
	head = new_node;

	return;
}

double Stack::pop()
{
	double val = head->get_data();

	head = head->get_next();
	delete head;

	return val;
}

double Stack::peek()
{
	return head->get_data();
}

bool Stack::is_empty()
{
	return (head == NULL);
}

bool Stack::is_full()
{
	return false; // This function is for the sake of backward compatibility with the older implementation of stack
}
