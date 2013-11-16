/*
 */

#include<iostream>

using namespace std;


int main()
{
	enum color {red, blue, green} e1;

	for (int i = static_cast<int>(red); i <= static_cast<int>(green) ; ++i)
	{
		e1 = static_cast<color>(i);
		cout << e1 << " " << i << endl;
	}
	
	return 0;
}

