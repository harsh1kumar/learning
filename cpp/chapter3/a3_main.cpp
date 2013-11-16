/*
 */

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main()
{
	string s;
	int integral_map = -1;

	while(integral_map != 0)
	{
		cout << "Enter a word: ";
		cin >> s;

		if (s == "Hello")
			integral_map = 1;
		else if (s == "Yellow")
			integral_map = 2;
		else if (s == "Exit")
			integral_map = 0;
		else
			integral_map = -1;

		switch(integral_map)
		{
			case -1: cout << "I don't understand what you wrote 'cause 'm stupid" << endl;
				break;
			case 0: cout << "Bye" << endl;
				break;
			case 1: cout << "You entered Hello" << endl;
				break;
			case 2: cout << "You entered Yellow" << endl;
				break;
			default: cout << "Something wrong happended" << endl;
				exit(1);
		}
	}

	return 0;
}
