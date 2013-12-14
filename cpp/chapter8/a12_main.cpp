/*
 *
 */

#include <iostream>

using namespace std;

int main()
{
	/* Wrong use of literal
	char * a = "Hello"; // Warning
	a[0] = 'h'; // Error
	cout << a << endl;
	*/
	
	char c[] = "Hello";
	c[0] = 'h';
	cout << c << endl;
}
