#include <iostream>
#include "arr_lib.h"

using namespace std;

/* To print the contents of array arr */
void print_arr(int arr[], const unsigned int& size)
{
	for (unsigned int i=0; i<size; ++i)
		cout << arr[i] << " ";
	cout << endl;
}

void swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}
