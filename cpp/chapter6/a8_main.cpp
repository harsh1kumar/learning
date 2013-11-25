/*
 * 
 */

#include <iostream>
#include <string>
#include "../chapter5/generic_stack.h"

using namespace std;

int main()
{
	string s[] = {	"Dieeff.",
			"Aabeec",
			"is",
			"name",
			"my",
			"Hello,"
			};
	Stack s_stack;

	for (unsigned int i=0; i < (sizeof s)/(sizeof *s); ++i)
	{
		s_stack.push(&s[i]);
	}

	cout << "\nAll strings pushed onto the stack. Now poping all values in reverse order:\n\t";
	while(!s_stack.is_empty())
	{
		cout << *(reinterpret_cast<string *>(s_stack.pop())) << " ";
	}
	cout << "\n\n";

	return 0;
}
