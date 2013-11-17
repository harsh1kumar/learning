/*
 */

#include<iostream>
#include <cstdio>

using namespace std;

typedef float (*(*fp1)(int))(char);
typedef float (* fp2)(char);

float func1(char c)
{
	return 0.0;
}

fp2 func2(int)
{
	return func1;
}

int main()
{
	fp1 fp1_var = func2;
	fp2 fp2_var= func1;

	printf("%p\n", fp2_var);
	fp2_var = (*fp1_var)(1);
	printf("%p\n", fp2_var);

	return 0;
}

