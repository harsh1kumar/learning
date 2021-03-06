#ifndef A8_STACK_H
#define A8_STACK_H

static const int STACK_SIZE = 100;

struct Stack
{
	private:
		double stack_arr[STACK_SIZE];
		int head;

	public:
		void initialize();
		void clear_stack();

		void push(double val);
		double  pop();
		double peek();

		bool is_empty();
		bool is_full();

};

#endif

