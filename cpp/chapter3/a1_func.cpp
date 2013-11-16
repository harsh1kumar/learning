#include "a1_func.h"
#include <iostream>

using namespace std;

int func1(float arg1, int arg2)
{
	cout << __PRETTY_FUNCTION__<< endl;
	return 0;
}

char func2(void)
{
	cout << __PRETTY_FUNCTION__<< endl;
	return 'a';
}

float func3(char arg1)
{
	cout << __PRETTY_FUNCTION__<< endl;
	return 0.1;
}

