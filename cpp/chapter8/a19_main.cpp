/*
 *
 */

class Foo
{
	float f1;
	const float f2;

public:
	Foo();
};

Foo::Foo() : f1(0.1), f2(0.2)
{
}

int main()
{
	return 0;
}
