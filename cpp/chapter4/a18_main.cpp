/*
 * 
 */

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

char * string_copy(char * in_sting)
{
	char * copyed_string = new char[strlen(in_sting) + 1];

	for(unsigned int i=0; i < strlen(in_sting)+1; ++i)
	{
		copyed_string[i] = in_sting[i];
	}

	return copyed_string;
}

int main()
{
	static char send_string[] = "Hey, I sent a string :)\n";
	char * ret_sting1;
	char * ret_sting2;

	ret_sting1 = string_copy(send_string);
	cout << ret_sting1;
	cout << "Address of the 1st returned string : " << reinterpret_cast<void *>(ret_sting1) << endl;

	ret_sting2 = string_copy(ret_sting1);
	cout << ret_sting2;
	cout << "Address of the 2nd returned string : " << reinterpret_cast<void *>(ret_sting2) << endl;

	delete []ret_sting1;
	delete []ret_sting2;

	return 0;
}

