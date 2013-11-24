/*
 * 
 */

#include "a7_helpers.h"
#include <iostream>

using namespace std;

void Hen::Nest::Egg::display()
{
	cout << "Inside Egg:\n";
	color = "Grey";
	cout << "\tEgg Color set to " << color << "\n\n";
}

void Hen::Nest::display()
{
	cout << "Inside Nest:\n";
	shape = "Round";
	egg1.color = "White";
	cout << "\tNest Shape set to " << shape << endl;
	cout << "\tEgg Color set to " << egg1.color << "\n\n";
}

void Hen::display()
{
	cout << "Inside Hen:\n";
	nest1.shape = "Oval";
	nest1.egg1.color = "Yellow";
	cout << "\tNest Shape set to " << nest1.shape << endl;
	cout << "\tEgg Color set to " << nest1.egg1.color << "\n\n";
}

