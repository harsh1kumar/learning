#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ifstream in("testfile");
	string s;
	char c;
	
	while(getline(in, s))
	{
		cout << s;
		while(getchar() != '\n');
	}
}
