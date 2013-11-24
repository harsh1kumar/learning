#ifndef A14_INT_STACH_H
#define A14_INT_STACH_H

class Int_stack
{
	class Cheshire;
	Cheshire * smile;
	
public:
	Int_stack();
	~Int_stack();

	void push(int i);
	int pop();
	int peek();
	bool is_empty();
};

#endif // A14_INT_STACH_H
