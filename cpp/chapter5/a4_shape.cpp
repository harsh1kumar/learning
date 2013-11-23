#include "a4_shape.h"
#include "a4_toy.h"
#include <iostream>

using namespace std;

int Shape::get_edge()
{
	return edge;
}

void Shape::demo_member_func(Toy * t)
{
	cout 	<< "In the member function of Shape. "
		<< "Color of toy is " << t->get_color() << endl;
}
