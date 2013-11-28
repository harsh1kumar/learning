#ifndef A2_MESSAGE_H
#define A2_MESSAGE_H

#include <string>

class Message
{
	std::string str;

public:
	Message(std::string s = "Hi! Wassup?\n");
	~Message();

	void print();
	void print(std::string s);
};

#endif // A2_MESSAGE_H
