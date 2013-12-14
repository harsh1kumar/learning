/*
 *
 */

#include <iostream>

using namespace std;

class Bird
{
	int weight;
public:
	Bird();
	void fly();
};

class Rock
{
	int weight;
public:
	Rock();
};

Bird::Bird() : weight(10) {}

void Bird::fly()
{
	cout << "The bird is flying :)\nThe weight of the bird is " << weight << " grams.\n";
}

Rock::Rock() : weight(1000) {}

int main()
{
	/* All sorts of crazy stuff going on here */
	Rock r;
	void * vp = &r;
	Bird * bp = reinterpret_cast<Bird *>(vp);

	bp->fly();

	return 0;
}

