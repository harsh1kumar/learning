/*
 * 
 */

#include "a9_demo_class.h"
#include <iostream>

using namespace std;

Demo_class::Demo_class(int i)
{
	val = i;
}

Demo_class::~Demo_class()
{
}

void Demo_class::print_val()
{
	cout << "val = " << val << endl;
}

