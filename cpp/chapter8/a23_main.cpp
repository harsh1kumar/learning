/*
 *
 */

#include <iostream>

using namespace std;

class Foo
{
	int a;

public:
	Foo(int i = 3);
	void func1();
	void func2() const;
};

Foo::Foo(int i) : a(i)
{
}

void Foo::func1()
{
	
}

void Foo::func2() const
{
	cout << "a = " << a << endl;
}

int main()
{
	Foo f1;
	Foo f2(10);
	const Foo f3(5);

	f1.func1();
	f1.func2();
	f2.func1();
	f2.func2();
	//f3.func1(); // Error
	f3.func2();

	return 0;
}


