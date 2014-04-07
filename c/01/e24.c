#include <stdio.h>

/*
 * Syntax Check: Unbalanced quotes, brackets
 */

#define TRUE 1
#define FALSE 0

#define NO_COMMENT 0
#define C_COMMENT 1
#define C99_COMMENT 2

int syntax_check(void)
{
	int c, old_c;
	int in_qoutes = FALSE;
	int comment_status = NO_COMMENT;
	int line_number = 1;
	int brackets = 0;

	while((c=getchar()) != EOF)
	{
		if (old_c != '\\' && c == '"' && comment_status == NO_COMMENT)
			in_qoutes = !in_qoutes;

		if (c == '(' && !in_qoutes && comment_status == NO_COMMENT)
			++brackets;
		if (c == ')' && !in_qoutes && comment_status == NO_COMMENT)
			--brackets;

		/* Set & modify comment status */
		if (old_c == '/' && c == '/' && comment_status==NO_COMMENT && !in_qoutes)
			/* Start of C99 comment */
			comment_status = C99_COMMENT;

		else if (c == '\n' && comment_status==C99_COMMENT)
			/* End of C99 comment */
			comment_status = NO_COMMENT;

		else if (old_c == '/' && c == '*' && comment_status==NO_COMMENT && !in_qoutes)
			/* Start of C comment */
			comment_status = C_COMMENT;

		else if (old_c == '*' && c == '/' && comment_status==C_COMMENT)
			/* End of C99 comment */
			comment_status = NO_COMMENT;


		if (c == '\n' && !in_qoutes && brackets==0)
			++line_number;

		if (c == ';' || c == '{' || c == '}')
		{
			if (in_qoutes)
			{
				printf("ERROR: Unbalanced quotes detected: Line %d\n", line_number);
				return 1;
			}
			if (brackets != 0)
			{
				printf("ERROR: Unbalanced brackets detected: Line %d\n", line_number);
				return 1;
			}
		}

		if (brackets < 0)
		{
			printf("ERROR: Unbalanced brackets detected: Line %d\n", line_number);
			return 1;
		}

		old_c = c;
	}
	return 0;
}

int main()
{
	return syntax_check();
}
