/*
 *
 */

#include <iostream>

using namespace std;

int main()
{
	const long * lp1;
	long const * lp2;
	long arr[10] = {0};

	lp1 = arr;
	lp2 = arr;

	lp1++;
	lp1--;
	lp2++;
	lp2--;

	arr[0] = 1;
	cout << arr[0];
	//lp1[0] = 2; // Error
	cout << " " << lp1[0];
	//lp2[0] = 3; // Error
	cout << " " << lp2[0] << endl;

	return 0;
}
