#include "a4_toy.h"
#include "a4_shape.h"
#include <iostream>

using namespace std;

string Toy::get_color()
{
	return color;
}

void Toy::demo_member_func(Shape * s)
{
	cout 	<< "In the member function of Toy. "
		<< "Edge of shape is " << s->get_edge() << endl;
}
