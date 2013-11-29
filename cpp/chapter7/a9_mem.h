#ifndef A9_MEM_H
#define A9_MEM_H

typedef unsigned char byte;

class Mem
{
	byte* mem;
	int size;
	void ensureMinSize(int minSize);

public:
	Mem(int sz = 0);
	~Mem();

	int msize();
	byte* pointer(int minSize = 0);
};

#endif // A9_MEM_H
