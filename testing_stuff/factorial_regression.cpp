/*
 * Factorial Calculation
 */

#include <iostream>

using namespace std;

unsigned int factorial(const unsigned int& no)
{
	if (no == 1 || no == 0)
		return 1;
	return no*factorial(no-1);
}

int main()
{
	unsigned int number = 1;
	cout << "Enter Number: ";
	cin >> number;
	cout << "Factorial " << number << "! = " << factorial(number) << endl;
	return 0;
}
