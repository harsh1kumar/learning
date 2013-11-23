#ifndef A4_SHAPE_H
#define A4_SHAPE_H

class Toy;

class Shape
{
	int edge;

public:
	Shape(int e) { edge = e; }

	int get_edge();
	void demo_member_func(Toy * t);
};

#endif // A4_SHAPE_H
