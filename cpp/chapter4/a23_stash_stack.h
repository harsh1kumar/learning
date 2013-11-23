/*
 * Defination of a stack using stashes.
 * Eack stash contains an array of strings.
 */

#ifndef A23_STASH_STACK
#define A23_STASH_STACK

#include <string>

class Stack
{
	class Stash
	{
		static const int STACK_SIZE = 5;
		std::string data[STACK_SIZE];
		int next_free_idx; // Next free index

	public:
		Stash * next;

		Stash(std::string s);
		~Stash();

		void insert(std::string s);
		std::string fetch();
		int get_next_free_idx();
		bool is_full();
	} * head;

public:
	Stack();
	~Stack();

	void push(std::string s);
	std::string pop();
	bool is_empty();
};

#endif // A23_STASH_STACK
