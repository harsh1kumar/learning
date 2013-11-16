#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char * argv[])
{
	float f = atof(argv[1]);
	unsigned char * c = reinterpret_cast<unsigned char *>(&f);
	for (int i = (sizeof f)-1; i>=0; --i)
	{
		for (int j=7; j>=0; --j)
		{
			cout << ((c[i] & (1<<j)) ? 1 : 0);
		}
		cout << " ";
	}
	cout << endl;
	return 0;
}
