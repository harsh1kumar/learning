#include <stdio.h>
#include <string.h>
#include "04_infix_to_postfix.h"

int main()
{
	char infix[] = "4*(5^2+1)-28/4";
	char postfix[strlen(infix)];

	in2postfix(infix, postfix);
	printf("%s\n%s\n\n", infix, postfix);

	return 0;
}
