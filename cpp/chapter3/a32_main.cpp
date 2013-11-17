/*
 */

#include<iostream>

using namespace std;

int func(double d)
{
	cout << "In func, the double argument is : " << d << endl;
	return (static_cast<int>(d) + 10);
}

int main()
{
	int (*fp)(double) = func;

	double d = 10;
	int a = (*fp)(d);

	cout << "Return value = " << a << endl;

	return 0;
}

