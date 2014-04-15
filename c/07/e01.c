/*
 * Program which converts lower case to upper if named upper 
 * 		&
 * 		 converts upper case to lower if named lower
 */ 

#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef int (*Toggle_t)(int);

int main(int argc, char * argv[])
{
	Toggle_t toggle_func;
	char c;

	if (strcmp(*argv, "lower") == 0 || strcmp(*argv, "./lower") == 0)
		toggle_func = tolower;
	else if (strcmp(*argv, "upper") == 0 || strcmp(*argv, "./upper") == 0)
		toggle_func = toupper;
	else
	{
		printf("Unrecognised program name\n");
		return 1;
	}

	while((c = getchar()) != EOF)
		putchar(toggle_func(c));

	return 0;
}

