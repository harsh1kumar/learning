#ifndef A1_TEXT_H
#define A1_TEXT_H

#include <string>

class Text
{
	std::string data;

public:
	Text();
	Text(std::string filename);
	~Text();

	std::string contents();
	
};

#endif
