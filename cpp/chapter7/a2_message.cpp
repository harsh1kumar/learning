/*
 * 
 */

#include "a2_message.h"
#include <iostream>

using namespace std;

Message::Message(string s)
{
	str = s;
}

Message::~Message()
{
	
}

void Message::print()
{
	cout << str << endl;
}

void Message::print(string s)
{
	cout << s << endl << str << endl;
}