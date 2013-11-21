/*
 * To demonstrate use of stack
 */

#include <iostream>
#include "a8_stack.h"

using namespace std;

int main()
{
	stack demo_stack;

	demo_stack.initialize();
	cout	<< "Is stack empty at the start? : " 
		<< ( demo_stack.is_empty() ? "True" : "False");

	demo_stack.push(99);
	cout << "\n99 pushed ----> poped value = " << demo_stack.pop();

	for (double i=0; i < 20; ++i) {
		demo_stack.push(i);
	}
	cout << "\n20 values pushed into the stack\n";
	cout << "Stack is " << (demo_stack.is_empty() ? "empty" : "not empty") << endl;
	cout << "Stack is " << (demo_stack.is_full() ? "full" : "not full") << endl;

	cout << "Now lets see the poped values:\n";
	for (int i=0; i < 20; ++i) {
		cout << demo_stack.pop() << " ";
	}
	cout << endl;

	for (double i=0; i < 100; ++i) {
		demo_stack.push(i);
	}
	cout << "\n100 values pushed into the stack\n";
	cout << "Stack is " << (demo_stack.is_empty() ? "empty" : "not empty") << endl;
	cout << "Stack is " << (demo_stack.is_full() ? "full" : "not full") << endl;
	cout << "Lets peek at the top value. It is " << demo_stack.peek() << endl;

	demo_stack.clear_stack();
	cout << "Stack cleared. It is " << (demo_stack.is_empty() ? "empty" : "not empty") << ".\n";

	return 0;
}


