/*
 * This will utilize the generic stack
 * This will also leverage the already present classes in a7
 */

#include <iostream>
#include "generic_stack.h"
#include "a7_helpers.h"

using namespace std;

int main()
{
	Stack s;
	Hen h1, h2, h3;
	Hen * ph;

	s.push(&h1);
	s.push(&h2);
	s.push(&h3);

	cout << "\n3 hens pushed onto the stack\n";
	cout << "Not poping the 3 hens in reverse order\n\n";

	ph = reinterpret_cast<Hen *>(s.pop());
	cout << "Hen #3 poped:\n";
	ph->display();
	ph->nest1.display();
	ph->nest1.egg1.display();

	ph = reinterpret_cast<Hen *>(s.pop());
	cout << "\nHen #2 poped:\n";
	ph->display();
	ph->nest1.display();
	ph->nest1.egg1.display();

	ph = reinterpret_cast<Hen *>(s.pop());
	cout << "\nHen #1 poped:\n";
	ph->display();
	ph->nest1.display();
	ph->nest1.egg1.display();
	
	cout << "Stack is " << (s.is_empty() ? "empty.\n" : "not empty!!!\n");

	return 0;
}