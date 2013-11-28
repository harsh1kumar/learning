/*
 * 
 */

#include "a7_stack.h"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char * argv[])
{
	string str_arr[] = { argv[0],
			"is ",
			"name ",
			"my ",
			"Hi, "
			};

	void * void_arr[(sizeof str_arr)/(sizeof *str_arr)];
	for (unsigned int i=0; i < (sizeof str_arr)/(sizeof *str_arr); ++i)
	{
		void_arr[i] = &str_arr[i];
	}

	Stack s(void_arr, (sizeof void_arr)/(sizeof *void_arr));

	string str_ind = "-->  ";
	s.push(&str_ind);

	while(!s.is_empty())
	{
		cout << *(reinterpret_cast<string *>(s.pop()));
	}
	cout << endl;

	return 0;
}
