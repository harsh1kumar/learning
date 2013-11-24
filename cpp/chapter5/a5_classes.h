#ifndef A5_CLASSES_H
#define A5_CLASSES_H

/*
 * 
 */

class X;

class Y
{
public:
	void set_a(X * x1, int val);
};

class Z
{
public:
	void set_a(X * x1, int val);
};

class X
{
	int a;

public:
	X();
	~X();

	int get_a();
	friend void Y::set_a(X * x1, int val);
	friend void Z::set_a(X * x1, int val);
};



#endif // A5_CLASSES_H
