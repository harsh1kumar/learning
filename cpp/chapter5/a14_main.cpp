/*
 * Option to link 2 different implementations of int stack
 * 	1.) a14_stack_int_arr.cpp
 * 	2.) a14_stack_int_vector.ccp
 */

#include <iostream>
#include "a14_int_stack.h"

using namespace std;

int main()
{
	Int_stack s;

	for (int i=0; i<10; ++i)
	{
		s.push(i);
	}
	cout << "\n10 values pushed into the stack\nNow poping 5 values in reverse:\n";
	
	for(int i=0; i<5; ++i)
	{
		cout << "\t" << s.pop() << endl;
	}
	cout << "Top value now = " << s.peek() << "\n";
	

	for (int i=5; i<20; ++i)
	{
		s.push(i);
	}
	cout << "\n15 values pushed into the stack\nNow poping all values in reverse:\n";
	
	for(int i=0; i<20; ++i)
	{
		cout << "\t" << s.pop() << endl;
	}
	cout << "\nThe stack is " << (s.is_empty() ? "empty.\n" : "not empty!!\n");

	return 0;
}
