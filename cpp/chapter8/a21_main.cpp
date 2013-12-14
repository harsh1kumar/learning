/*
 * 
 */

#include <iostream>

using namespace std;

class Foo
{
	enum { arr_size = 10 };
	int arr[arr_size];
	const int aaa;

public:
	Foo(int a);
	void print() const;
};

Foo::Foo(int a) : aaa(a)
{
	for (int i=0; i<arr_size; ++i)
		arr[i] = i;
}

void Foo::print() const
{
	cout << "arr_size = " << arr_size << endl;
	for (int i=0; i<arr_size; ++i)
		cout << arr[i] << " ";
	cout << "\naaa = " << aaa << endl;
}

int main()
{
	const Foo f(55);
	f.print();
	return 0;
}
