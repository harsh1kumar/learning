/*
 * 
 */

#include "a5_classes.h"
#include <iostream>

using namespace std;

int main()
{
	X x1;
	Y y1;
	Z z1;

	cout << "a = " << x1.get_a() << endl;

	y1.set_a(&x1, 10);
	cout << "a = " << x1.get_a() << endl;

	z1.set_a(&x1, 20);
	cout << "a = " << x1.get_a() << endl;

	return 0;
}
