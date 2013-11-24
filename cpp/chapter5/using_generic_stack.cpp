/*
 * To demonstrate the use of the generic stack
 */

#include <iostream>
#include <string>
#include <fstream>

#include "generic_stack.h"

using namespace std;

int main()
{
	Stack demo_stack;
	ifstream in_file("testfile", ifstream::in);
	string line;
	string * ps;

	while( getline(in_file, line) )
	{
		ps = new string;
		*(ps) = line;
		demo_stack.push(ps);
	}

	cout << "All line of the file pushed into the stack\nPeeking at the top:\t";
	cout << *(reinterpret_cast<string *>(demo_stack.peek())) << "\n\n";
	cout << "Now poping. File contents in reverse:\n";

	while( !demo_stack.is_empty() )
	{
		ps = reinterpret_cast<string *>(demo_stack.pop());
		cout << *(ps) << endl;
		delete ps;
	}

	in_file.close();

	return 0;
}
