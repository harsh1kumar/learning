/*
 * Convert infix expression to postfix expression
 * Uses the stack : 03_stack_ll.c/.h
 */

#include "04_infix_to_postfix.h"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "03_stack_ll.h"

#define MAX_EXPRESSION_LEN 10

static int pref(char op);

void in2postfix(char * infix, char * postfix)
{
	int len;

	struct stack_node * top = NULL;
	char * pop_val;

	len = 0;
	while(*infix)
	{
		if ( isdigit(*infix) )
		{
			while ( isdigit(*infix) )
				postfix[len++] = *(infix++);
			postfix[len++] = ' ';
		}
		else if ( isblank(*infix) )
		{
			++infix;
			continue;
		}
		else
		{
			switch (*infix)
			{
				case ( '(' ):
					push(&top, infix);
					break;

				case ( ')' ):
					while ( *(pop_val = (char *)pop(&top)) != '(')
					{
						postfix[len++] = *pop_val;
						postfix[len++] = ' ';
					}
					break;

				case ('^'): case ('*'): case ('/'): case ('+'): case ('-'):
				{
					while (is_empty(top) == FALSE)
					{
						pop_val = (char *)pop(&top);
						if (  pref(*pop_val) >= pref(*infix) )
						{
							postfix[len++] = *pop_val;
							postfix[len++] = ' ';
						}
						else
						{
							push(&top, pop_val);
							break;
						}
					}
					push(&top, infix);
					break;
				}

				default:
					fprintf(stderr, "Error: Unexpected character. Check the infix expression\n");
					exit(1);
					break;
			}
			++infix;
		}
	}

	while ( is_empty(top) == FALSE)
	{
		postfix[len++] = *(char *)pop(&top);
		postfix[len++] = ' ';
	}
	postfix[len] = '\0';

	return;
}

static int pref(char op)
{
	int p = 0;

	switch (op)
	{
		case ('^'):
			++p;
		case ('*'): case ('/'):
			++p;
		case ('+'): case ('-'):
			++p;
		case ('('): case (')'):
			++p;
			break;

		default:
			fprintf(stderr, "Error: Unexpected operator op supplied to pref\n");
			exit(1);
			break;
	}
	return p;
}



