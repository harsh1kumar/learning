/*
 * 
 */

#include <iostream>
#include "a1_text.h"

using namespace std;

int main()
{
	Text file_text("testfile");

	cout << "The contents of the file are : \n" << file_text.contents();

	return 0;
}
