/*
 *
 */

void foo(float f)
{
	const float& cf = f;
	cf = 10.1; // Error
}

int main()
{
	foo(5.5);
	return 0;
}
