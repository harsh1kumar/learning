#ifndef A7_HELPERS_H
#define A7_HELPERS_H

#include <string>

class Hen
{
public:
	class Nest
	{
		std::string shape;

	public:
		class Egg
		{
			std::string color;

		public:
			void display();
			friend Nest;
			friend Hen;
		} egg1;

		void display();
		friend Hen;
	} nest1;

	void display();

};

#endif // A7_HELPERS_H
