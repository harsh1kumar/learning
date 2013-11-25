#ifndef A4_DUMMY_H
#define A4_DUMMY_H
/*
 * 
 */

#include <iostream>

class Dummy
{
public:
	Dummy() {};
	~Dummy() { std::cout << "Destructor Called\n";}

	int val;

};

#endif // A4_DUMMY_H
