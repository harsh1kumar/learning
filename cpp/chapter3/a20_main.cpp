/*
 */

#include <iostream>

using namespace std;

typedef struct
{
	int red;
	int green;
	int blue;
} color;

int main()
{
	color c[3];

	cout << "c : " << (c) << endl;
	cout << "&c : " << (&c) << endl;
	cout << "&c[0] : " << (&c[0]) << endl;
	cout << "&c[1] : " << (&c[1]) << endl;
	cout << "&c[2] : " << (&c[2]) << endl;
	
	return 0;
}

