/*
 */

#include <iostream>
#include <string>

using namespace std;

void why_string(string * s)
{
	*s = "Why is " + *s;
}

void ref_string(string& s)
{
	s = s + " reference";
}

int main()
{
	string s = "This is a string";

	cout << s <<endl;

	why_string(&s);
	cout << s <<endl;

	ref_string(s);
	cout << s <<endl;
	
	return 0;
}

