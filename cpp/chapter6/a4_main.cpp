/*
 * To demonstrate that destructor is still called even if there is jump using goto
 */

#include <iostream>
#include "a4_dummy.h"

using namespace std;

int main()
{
	{
		Dummy d;
		for(int i=0; i<100; ++i)
		{
			;
			if (i!=20)
			{
				d.val = i;
			}
			else
			{
				cout << "Goto encountered, jumping\n";
				goto PRINT;
			}
		}
	}
	
PRINT:	cout << "Outside Loop\n";
	
	return 0;
}
