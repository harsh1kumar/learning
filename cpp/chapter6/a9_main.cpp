/*
 * 
 */

#include "a9_demo_class.h"

using namespace std;

int main()
{
	Demo_class d[] = { 	Demo_class(5), 
				Demo_class(10), 
				Demo_class(15),
				Demo_class(20),
				Demo_class(25),
				Demo_class(30)
			};

	for (unsigned int i=0; i < (sizeof d)/(sizeof *d); ++i)
	{
		d[i].print_val();
	}

	return 0;
}
