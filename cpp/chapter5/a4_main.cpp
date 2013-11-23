/*
 * 
 */

#include "a4_shape.h"
#include "a4_toy.h"

using namespace std;

int main()
{
	Shape square(4);
	Toy teddy("white");

	square.demo_member_func(&teddy);
	teddy.demo_member_func(&square);

	return 0;
}
