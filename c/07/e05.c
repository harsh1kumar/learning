/*
 * Simple postfix calculator
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXWORD 10

int getword(char * word, int maxlen);
void operate(char * word);

/* STACK */
int is_full(void);
int is_empty(void);
void push(double num);
double pop(void);

int main()
{
	char word[MAXWORD];
	double ans;

	while(getword(word, MAXWORD) != EOF)
	{
		if ( isdigit(*word) || ( *word == '-' && isdigit(*(word+1)) ) )
			push(atof(word));
		else
			operate(word);
	}

	ans = pop();
	if (!is_empty())
	{
		fprintf(stderr, "Error: Improper postfix expression\n");
		exit(6);
	}
	printf("\nAnswer = %f\n\n", ans);

	return 0;
}

int getword(char * word, int maxlen)
{
	char fmt[MAXWORD];

	sprintf(fmt, "%%%ds ", maxlen);

	if (scanf(fmt, word) != 1)
		return EOF;
	else
		return 1;
}

void operate(char * word)
{
	double right;
	if (strlen(word) != 1)
	{
		fprintf(stderr, "Error: Unexpected characters\n");
		exit(3);
	}

	switch (*word)
	{
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
				fprintf(stderr, "Error: Divide by zero\n");
				exit(1);
			}
			push(pop() / right);
			break;

		default:
			fprintf(stderr, "Error: Unexpected character in place of operator\n");
			exit(2);
			break;
	}
}


/**********************
 *	STACK
 **********************/

#define MAXSTACK 10

double stack[MAXSTACK];
int sp = 0;

int is_full()
{
	return !(MAXSTACK - sp);
}

int is_empty()
{
	return !sp;
}

void push(double num)
{
	if (is_full())
	{
		fprintf(stderr, "Error: Stack Full. Pushing into a full stack.\n");
		exit(4);
	}

	stack[sp++] = num;
}

double pop(void)
{
	if (is_empty())
	{
		fprintf(stderr, "Error: Poping from an empty stack. Please check the postfix expression.\n");
		exit(5);
	}

	return stack[--sp];
}


