/*
 */

#include <iostream>
#include <string>

using namespace std;

#define DF(FN) \
		string FN(void) \
		{ \
			string s = "Function : "; \
			return s + #FN + "\n"; \
		}

DF(a);
DF(b);
DF(c);
DF(d);


int main()
{
	string (*fp_arr[])(void) = {a, b, c, d};
	string s;

	for (int i = 0; i<4; ++i)
	{
		s += (*fp_arr[i])() ;
	}
	cout << s;

	return 0;
}

