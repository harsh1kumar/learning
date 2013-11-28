/*
 * 
 */

#include "a1_text.h"
#include <fstream>
#include <cstring>
#include <cassert>

using namespace std;

Text::Text()
{
}

Text::Text(string filename)
{
	ifstream instr(filename.c_str(), ifstream::in); // Open file
	assert(instr.is_open());
	string line;

	while(getline(instr, line))
	{
		data += (line + '\n');
	}
	instr.close();
}

Text::~Text()
{
}

string Text::contents()
{
	return data;
}

