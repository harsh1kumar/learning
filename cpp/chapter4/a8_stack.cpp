/*
 * Definations for stack
 */

#include "a8_stack.h"

using namespace std;

void Stack::initialize()
{
	for(int i=0; i <STACK_SIZE; ++i)
		stack_arr[i] = 0;

	head = -1;

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
	stack_arr[++head] = val;

	return;
}

double Stack::pop()
{
	return stack_arr[head--];
}

double Stack::peek()
{
	return stack_arr[head];
}

bool Stack::is_empty()
{
	return (head == -1);
}

bool Stack::is_full()
{
	return (head == STACK_SIZE - 1);
}
