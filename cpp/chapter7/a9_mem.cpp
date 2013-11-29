/*
 * 
 */

#include "a9_mem.h"
#include <cstring>

using namespace std;

Mem::Mem(int sz)
{
	mem = 0;
	size = 0;
	ensureMinSize(sz);
}

Mem::~Mem()
{
	delete []mem;
}

void Mem::ensureMinSize(int minSize)
{
	if (minSize > size)
	{
		byte * new_mem = new byte[minSize];
		memset(new_mem + size, 0, minSize - size);
		memcpy(new_mem, mem, size);
		size  = minSize;
		delete []mem;
		mem = new_mem;
	}
}

int Mem::msize()
{
	return size;
}

byte* Mem::pointer(int minSize)
{
	ensureMinSize(minSize);
	return mem;
}

