/*
 * Definations for stack
 */

#include "a8_stack.h"

using namespace std;

void stack::initialize()
{
	for(int i=0; i <STACK_SIZE; ++i)
		stack_arr[i] = 0;

	head = -1;

	return;
}

void stack::clear_stack()
{
	while(!is_empty())
		pop();

	return;
}

void stack::push(double val)
{
	stack_arr[++head] = val;

	return;
}

double stack::pop()
{
	return stack_arr[head--];
}

double stack::peek()
{
	return stack_arr[head];
}

bool stack::is_empty()
{
	return (head == -1);
}

bool stack::is_full()
{
	return (head == STACK_SIZE - 1);
}
