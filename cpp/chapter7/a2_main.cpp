/*
 * 
 */

#include "a2_message.h"

using namespace std;

int main()
{
	Message m1, m2("Hello Sir, how are you doing today?\n");

	m1.print();
	m2.print();
	
	m1.print("So, here is the stored string:");
	m2.print("So, here is the stored string:");

	return 0;
}
