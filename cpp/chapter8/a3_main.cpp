/*
 *
 */

int main()
{
	const int a = 1;
	const short b = 2;
	const long c = 3;

	const unsigned int d = 4;
	const unsigned short int e = 5;
	const unsigned long f = 6;

	const char g = 'a';
	const unsigned char h = 'a';
	const signed char i = 'a';

	const float j = 0.1;
	const double k = 0.1;

	const void * l = 0;

	const struct { int a; int b;} m = {a, b};

	int n = c;
	int o = b;
	char p = h;

	return 0;
}
