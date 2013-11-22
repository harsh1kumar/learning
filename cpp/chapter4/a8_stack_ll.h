#ifndef A8_STACK_LL_H
#define A8_STACK_LL_H

/*
 * Stack as a linked list
 */

class Stack
{
private:
	class Node
	{
	private:
		double data;
		Node * next;

	public:
		// Not using default constuctors & destructors intentionally.
		void init(double in_data, Node * in_next);
		inline void destruct();

		inline double get_data();
		inline Node * get_next();
	} * head;

public:
	// Not using default constuctors & destructors intentionally.
	void initialize();
	void clear_stack(); // Frees up stack

	void push(double val);
	double pop();
	double peek();

	bool is_empty();
	bool is_full(); // No real use in this implementation of stack
};

typedef Stack stack; // WARNING: Bad way of coding. Change in alternative stack class implementation required.

#endif
