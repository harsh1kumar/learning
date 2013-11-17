/*
 */

#include <iostream>

using namespace std;

int main()
{
	float f = 6.0;
	unsigned char * c = reinterpret_cast<unsigned char *>(&f);

	for (int i = sizeof(float)-1; i>=0 ; --i)
	{
		for (int j = 7; j>=0; --j)
		{
			cout << ((c[i] & (1<<j)) ? 1 : 0);
		}
		cout << " ";
	}
	cout << endl;

	return 0;
}

