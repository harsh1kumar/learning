/*
 */

#include <iostream>

using namespace std;

int main()
{
	const double d1[5] = {0};
	volatile double d2[5] = {0};

	for (int i=0; i<5; ++i)
	{
		const_cast<double *>(d1)[i] = i;
		const_cast<double *>(d2)[i] = i;
	}

	for (int i=0; i<5; ++i)
	{
		cout << d1[i] << " " << d2[i] << endl;
	}

	return 0;
}

