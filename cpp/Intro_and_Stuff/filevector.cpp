#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	vector<string> vs;
	ifstream in("testfile");
	string line, all_line;

	while(getline(in, line))
	{
		vs.push_back(line);
	}

	for(int i=0; i < vs.size(); i++)
	{
		all_line = all_line + vs[i];
	}
	cout<< all_line <<endl;
	in.close();
	return 0;
}
