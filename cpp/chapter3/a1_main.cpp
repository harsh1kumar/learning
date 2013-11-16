/*
 */

#include "a1_func.h"
#include <iostream>

using namespace std;

int main()
{
	int a = func1(0.0, 1);
	char b = func2();
	float c = func3('a');

	cout << "Return values = " << a << b << c << endl;
	return 0;
}

