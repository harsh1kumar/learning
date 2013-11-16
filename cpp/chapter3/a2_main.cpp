/*
 */

#include<iostream>

using namespace std;

#define UPTO 200

int main()
{
	bool prime = true; //Intially, assume number to be prime

	cout << "Primes upto " << UPTO << endl;
	for (int i=2; i <= UPTO; ++i)
	{
		int j = 2;
		for (j=2; j<i; ++j)
		{
			if (!(i%j))
				break;
		}
		if (i == j)
			cout << i << endl;
	}
	return 0;
}

