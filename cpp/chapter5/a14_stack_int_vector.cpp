/*
 * Int_stack implemented using a int array
 */

#include "a14_int_stack.h"
#include <cassert>
#include <vector>

using namespace std;

class Int_stack::Cheshire
{
	vector<int> data;

public:
	friend Int_stack;
};


Int_stack::Int_stack()
{
	smile = new Cheshire;
}

Int_stack::~Int_stack()
{
	while(smile->data.size() != 0)
		smile->data.pop_back();

	assert(is_empty()); // pop all values before destructing
	delete smile;
}

void Int_stack::push(int i)
{
	smile->data.push_back(i);
}

int Int_stack::pop()
{
	assert(smile->data.size() != 0);

	int retval = smile->data.back();
	smile->data.pop_back();

	return retval;
}

int Int_stack::peek()
{
	return smile->data.back();
}

bool Int_stack::is_empty()
{
	return (smile->data.size() == 0);
}



