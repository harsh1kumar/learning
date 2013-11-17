/*
 */

#include <iostream>

using namespace std;

void put_byte_val(void * vp, int no_of_byte, char val)
{
	for (int i=0; i<no_of_byte; ++i)
	{
		reinterpret_cast<char *>(vp)[i] = val;
	}
}

int main()
{
	int a[10];

	put_byte_val(reinterpret_cast<void *>(a), 10*sizeof(int), 1);

	for(int i=0; i<10; ++i)
		cout << a[i] << " ";
	cout << endl;

	return 0;
}

