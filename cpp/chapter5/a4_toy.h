#ifndef A4_TOY_H
#define A4_TOY_H

#include <string>

class Shape;

class Toy
{
	std::string color;

public:
	Toy(std::string c) { color = c; }

	std::string get_color();
	void demo_member_func(Shape * s);
};

#endif // A4_TOY_H
