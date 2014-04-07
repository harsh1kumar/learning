#include <stdio.h>

/*
 * Remove all comments from c code
 */

#define TRUE 1
#define FALSE 0

#define NO_COMMENT 0
#define C_COMMENT 1
#define C99_COMMENT 2

void remove_comments(void)
{
	int c, old_c;
	int comment_status = NO_COMMENT;
	int in_qoutes = FALSE;

	while((c=getchar()) != EOF)
	{
		/* Check for quotes */
		if (old_c != '\\' && c == '"')
			in_qoutes= !in_qoutes;

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
		{
			/* End of C99 comment */
			comment_status = NO_COMMENT;
			old_c = '\0'; // old_c shouldn't be printed, so made null
			continue;
		}
		else if(comment_status == NO_COMMENT)
			putchar(old_c);


		old_c = c;
	}

	/* Print the last character */
	if(comment_status == NO_COMMENT)
	{
		putchar(old_c);
	}
}

int main()
{
	remove_comments();

	return 0;
}
