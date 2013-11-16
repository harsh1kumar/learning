/*
 */

#include <iostream>

using namespace std;

#define PRINT(PS) \
	cout << #PS " : " << (PS) << endl;

int main()
{
	PRINT(1 and 1);
	PRINT(0 and 1);
	PRINT(0 and 0);
	PRINT(1 or 1);
	PRINT(0 or 1);
	PRINT(0 or 0);
	PRINT(not 1);
	PRINT(not 0);
	PRINT(5 bitand 7);
	PRINT(5 bitor 7);
	PRINT(5 xor 7);
	PRINT(compl 5);
	PRINT(1 not_eq 0);

	return 0;
}

