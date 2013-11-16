/*
 */

#include<iostream>
#include <string>

using namespace std;

typedef struct
{
	string s1;
	string s2;
	int i;
} my_struct;

int main()
{
	my_struct s = {"abc", "xyz", 5};

	cout << s.s1 << " " << s.s2 << " " << s.i << endl;

	my_struct * ptr_s = &s;

	ptr_s->s1 = "String1";
	ptr_s->s2 = "String2";
	ptr_s->i = 1;
	cout << ptr_s->s1 << " " << ptr_s->s2 << " " << ptr_s->i << endl;

	return 0;
}

