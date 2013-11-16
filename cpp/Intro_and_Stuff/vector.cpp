#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<float> vf;
	int i;

	for (i=0; i<10; i++)
	{
		vf.push_back(i);
	}
	
	for (i=0; i<10; i++)
	{
		vf[i] *= vf[i];
		cout<< vf[i] << ", ";
	}
	cout << endl;

}
