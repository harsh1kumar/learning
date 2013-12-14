/*
 * 
 */

class Foo
{
	volatile char c;

public:
	void func1();
	void func2() volatile;
};

void Foo::func1()
{
	c = 't';
}

void Foo::func2() volatile
{
	c = 'p';
}

int main()
{
	Foo f1;
	volatile Foo f2;

	f1.func1();
	f1.func2();
	//f2.func1(); // Error
	f2.func2();

	return 0;
}
