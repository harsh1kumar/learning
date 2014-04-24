#include <stdio.h>
#include <string.h>

#include "05_postfix.h" 
#include "04_infix_to_postfix.h"

/* NOTE: Postfix expression must have operands & operators separated by space */

int main()
{
	char expression[] = "5 * (6 + 2^2) - 12/4";
	char postfix[strlen(expression)];

	in2postfix(expression, postfix);
	printf("%s\n%s\n", expression, postfix);
	printf("Ans = %d\n", postfix_eval(postfix));

	return 0;
}

