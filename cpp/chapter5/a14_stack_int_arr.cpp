/*
 * Int_stack implemented using a int array
 */

#include "a14_int_stack.h"
#include <cassert>

using namespace std;

class Int_stack::Cheshire
{
	static const int STACK_SIZE = 20;
	int data[STACK_SIZE];
	int head;

public:
	friend Int_stack;
};


Int_stack::Int_stack()
{
	smile = new Cheshire;
	smile->head = -1;
}

Int_stack::~Int_stack()
{
	delete smile;
}

void Int_stack::push(int i)
{
	assert(smile->head != (smile->STACK_SIZE-1));
	smile->data[++smile->head] = i;
}

int Int_stack::pop()
{
	assert(!is_empty());
	return smile->data[smile->head--];
}

int Int_stack::peek()
{
	return smile->data[smile->head];
}

bool Int_stack::is_empty()
{
	return (smile->head == -1);
}



