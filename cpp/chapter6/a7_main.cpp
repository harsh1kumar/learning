/*
 * 
 */

#include <iostream>

using namespace std;

int main()
{
	double a1[10] = {1,2,3,4,5};
	double a2[] = {1,2,3,4,5};
	
	cout << "a1 -> ";
	for (unsigned int i = 0; i < (sizeof a1)/(sizeof *a1); ++i)
	{
		cout << a1[i] << " ";
	}

	cout << "\na2 -> ";
	for (unsigned int i = 0; i < (sizeof a2)/(sizeof *a2); ++i)
	{
		cout << a2[i] << " ";
	}
	cout << endl;

	return 0;
}
