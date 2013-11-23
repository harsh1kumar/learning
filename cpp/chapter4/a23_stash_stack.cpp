/*
 * Implementation of Stack using Stashes
 */

#include "a23_stash_stack.h"
#include <cassert>


using namespace std;

Stack::Stash::Stash(string s)
{
	next_free_idx = 0;
	data[next_free_idx++] = s;
}

Stack::Stash::~Stash()
{
}

void Stack::Stash::insert(string s)
{
	assert(next_free_idx < STACK_SIZE);
	data[next_free_idx++] = s;
}

string Stack::Stash::fetch()
{
	assert(next_free_idx != 0);
	return data[--next_free_idx];
}

int Stack::Stash::get_next_free_idx()
{
	return next_free_idx;
}

bool Stack::Stash::is_full()
{
	return (next_free_idx == STACK_SIZE);
}

Stack::Stack()
{
	head = 0;
}

Stack::~Stack()
{
}

void Stack::push(string s)
{
	if (is_empty())
	{
		head = new Stash(s);
		head->next = 0;
	}
	else
	{
		if (head->is_full())
		{
			// Current Stash is full, create a new one
			Stash * new_stash = new Stash(s);
			new_stash->next = head;
			head = new_stash;
		}
		else
		{
			head->insert(s);
		}
	}
}

string Stack::pop()
{
	assert(!is_empty()); // Never call pop is stack is empty

	string retval = head->fetch();
	if (head->get_next_free_idx() == 0)
	{
		// If stash becomes empty after fetch, delete that stash
		Stash * temp = head->next;
		delete head;
		head = temp;
	}

	return retval;
}

bool Stack::is_empty()
{
	return (head == 0);
}



