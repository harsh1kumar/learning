
#include "e03_getword.h"

#include <stdio.h>
#include <ctype.h>

int my_getchar(void);
void my_ungetc(int c); 

int getword(char * word, int max_len)
{
	char * w = word;

	while(isblank(*w = my_getchar()))
		;
	--max_len;

	if (!isalpha(*w) && *w != '_')
	{
		*++w = '\0';
		return word[0];
	}

	for(; (isalnum(*w) || *w == '_') && max_len; --max_len)
		*++w = my_getchar();

	my_ungetc(*w);
	*w = '\0';

	return word[0];
}

enum Bool {FALSE, TRUE};
enum Comments {NO_COM, C_COM, C99_COM};
enum Buff_status {EMPTY, FULL};

int buff;
enum Buff_status buffstatus = EMPTY;

void my_ungetc(int c)
{
	buff = c;
	buffstatus = FULL;
}

int my_getchar()
{
	int c;
	static int old_c;
	static enum Bool in_quotes = FALSE;
	static enum Bool preproc = FALSE;
	static enum Comments com = NO_COM;

	if (buffstatus == FULL)
	{
		buffstatus = EMPTY;
		return buff;
	}

	for ( ; (c=getchar()) != EOF; old_c = c)
	{
		if (c == '#' && old_c == '\n' && in_quotes == FALSE && com == NO_COM)
		{
			preproc = TRUE;
			continue;
		}
			
		if (c == '"' && old_c != '\\' && com == NO_COM)
		{
			in_quotes = (in_quotes == TRUE) ? FALSE : TRUE;
			continue;
		}

		if (c == '\n' && old_c != '\\')
		{
			in_quotes = FALSE;
			if (com == C99_COM)
				com = NO_COM;
			if (preproc == TRUE)
				preproc = FALSE;
		}

		if (c == '/' && com == NO_COM && in_quotes == FALSE)
		{
			old_c = c;
			c = getchar();
			if (c == '*')
			{
				com = C_COM;
				continue;
			}
			else if (c == '/')
			{
				com = C99_COM;
				continue;
			}
			else
			{
				ungetc(c, stdin);
				break;
			}
		}

		if (c == '*' && com == C_COM && in_quotes == FALSE)
		{
			old_c = c;
			c = getchar();
			if (c == '/')
			{
				com = NO_COM;
				continue;
			}
			else
			{
				ungetc(c, stdin);
				break;
			}
		}

		if (in_quotes == FALSE && com == NO_COM && preproc == FALSE)
			break;

	}

	old_c = c;
	return c;

}

