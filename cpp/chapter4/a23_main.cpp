/*
 * Reads a file & stores each line in a stack
 */

#include "a23_stash_stack.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	Stack line_stack;
	ifstream infile ("testfile", ifstream::in);
	string line;

	while( getline(infile, line) )
	{
		line_stack.push(line);
	}

	cout 	<< "Whole file is in the stack line by line\n"
		<< "Now poping the stack\n"
		<< "File Contents:\n\n";
	while(!line_stack.is_empty())
	{
		cout << line_stack.pop() << endl;
	}
	cout << endl;

	infile.close();

	return 0;
}
