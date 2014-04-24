/*
 * Evaluate postfix expression
 * Using stack implemented in 03_stack_ll.c/.h
 * Postfix expression must have operands & operators separated by space
 */

#include "03_stack_ll.h"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAX_EXPRESSION_LEN 10

/* Postfix expression must have operands & operators separated by space */
int postfix_eval(char * postfix)
{
	int * data;
	int * left;
	int * right;
	int result;

	int i;
	char expression[MAX_EXPRESSION_LEN];

	struct stack_node * top = NULL;

	while(*postfix)
	{
		i=0;
		while(isblank(*postfix))
			++postfix;

		while( (!isblank(*postfix)) && (*postfix != '\0'))
		{
			expression[i++] = *(postfix++);
		}
		expression[i] = '\0';
		if (*postfix == '\0')
			break;

		if ( isdigit(*expression) )
		{
			data = (int *) malloc( sizeof(int) );
			if (data == NULL)
			{
				fprintf(stderr, "Error: Memory allocation failed\n");
				exit(1);
			}
			*data = atoi(expression);
			push(&top, data);
		}
		else
		{
			right = (int *)pop(&top);
			left = (int *)pop(&top);

			data = (int *) malloc( sizeof(int) );
			if (data == NULL)
			{
				fprintf(stderr, "Error: Memory allocation failed\n");
				exit(1);
			}

			switch (*expression)
			{
				case ('+'):
					*data = *left + *right;
					break;

				case ('*'):
					*data = (*left) * (*right);
					break;

				case ('-'):
					*data = *left - *right;
					break;

				case ('/'):
					if ( *right == '0')
					{
						fprintf(stderr, "Error: Divide by zero\n");
						exit(1);
					}
					*data = (*left) / (*right);
					break;

				case ('^'):
					*data = pow(*left, *right);
					break;

				default:
					fprintf(stderr, "Error: Unexpected character. Check the postfix expression\n");
					exit(1);
					break;
			}

			free(left);
			free(right);

			push(&top, data);
		}
	}

	data = (int *)pop(&top);
	result = *data;
	free(data);

	return result;
}


