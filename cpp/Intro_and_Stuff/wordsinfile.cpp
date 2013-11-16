#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ifstream in("testfile");
	int i, words = 0;
	string s;

	while(in >> s)
		words++;

	ifstream in1("testfile");
	for(i=0; in1 >> s; i++)
		;
		
	cout<< "words = " << words << " i = " << i <<endl;
}
