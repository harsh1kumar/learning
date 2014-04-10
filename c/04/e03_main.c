/*
 * Basic calculator for Polish notation
 */

#include <stdio.h>
#include <stdlib.h>

#include "e03_getop.h"
#include "e03_stack.h"

#define STR_LEN 7

int main()
{
	int c;
	char s[STR_LEN];
	double right; // To store the right operand for -,/,%
	double left; // To store the left operand for %

	while((c=getop(s)) != EOF)
	{
		switch (c)
		{
			case NUMBER:
				push(atof(s));
				break;

			case '+':
				push(pop() + pop());
				break;

			case '*':
				push(pop() * pop());
				break;

			case '-':
				right = pop();
				push(pop() - right);
				break;

			case '/':
				right = pop();
				if (right == 0)
				{
					fprintf(stderr, "\nERROR: Trying to divide by zero\n");
					return 1;
				}
				push(pop() / right);
				break;

			case '%':
				right = pop();
				left = pop();
				if (right == 0)
				{
					fprintf(stderr, "\nERROR: Trying to divide by zero\n");
					return 1;
				}

				if ((right - (int)right) || (left - (int)left))
				{
					fprintf(stderr, "\nERROR: %% operator cannot be applied to floating point numbers\n");
					return 1;
				}
				push((int)left % (int)right);
				break;
		}
	}

	printf("\n\nAnswer = %f\n", pop());

	return 0;
}

