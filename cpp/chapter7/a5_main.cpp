/*
 * You can define PLACEHOLDER on command line using -DPLACEHOLDER
 */

#include <iostream>

using namespace std;

#ifndef PLACEHOLDER

	void print(int a, int b)
	{
		cout << a << endl;
		cout << b << endl;
	}
#else
	void print(int , int b)
	{
		cout << b << endl;
	}
#endif

int main()
{
	print(10,20);
	return 0;
}
