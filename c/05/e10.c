/*
 * Evaluate polish expression
 */

#include <stdio.h>
#include <stdlib.h>

void push(double num);
double pop(void);

int main(int argc, char * argv[])
{
	int right;

	while(--argc)
	{
		if (isdigit((*++argv)[0])) /* Operand */
			push(atof(*argv));
		else
		{
			/* Operator */
			switch ((*argv)[0])
			{
				case ('+'):
					push(pop() + pop());
					break;

				case ('*'):
					push(pop() * pop());
					break;

				case ('-'):
					right = pop();
					push(pop() - right);
					break;

				case ('/'):
					right = pop();
					if (right == 0)
					{
						fprintf(stderr, "Error: Divide by zero\n");
						return 1;
					}
					push(pop() / right);
					break;

				default:
					fprintf(stderr, "Wrong arguments\n");
					return 1;
					break;
			}
		}
	}

	printf("Answer = %f\n", pop());

	return 0;
}

#define STACK_SIZE 10

double stack[STACK_SIZE];
int sp=0;

void push(double num)
{
	if (sp != STACK_SIZE)
		stack[sp++] = num;
	else
		fprintf(stderr, "Error: Pushing into a full stack\n");
}

double pop()
{
	if (sp != 0)
		return stack[--sp];
	else
	{
		fprintf(stderr, "Error: Poping from empty stack\n");
		return 0;
	}
}
