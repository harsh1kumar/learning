/*
 * 
 */

#include "a5_classes.h"
#include <iostream>

using namespace std;

void Y::set_a(X * x1, int val)
{
	x1->a = val;
	cout << "In set_a() of Y.\na set to " << x1->a << endl;
}

void Z::set_a(X * x1, int val)
{
	x1->a = val;
	cout << "In set_a() of Z.\na set to " << x1->a << endl;
}

X::X()
{
	a = 0;
}

X::~X()
{
}

int X::get_a()
{
	return a;
}
