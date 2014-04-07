/*
 * escape(s,t): put escape seqence in 't' in place of escape characters in 's'
 * de_escape(s, t) : reverse
 */

#include <stdio.h>

#define STR_LEN 100

void escape(char s[], char t[])
{
	int i = 0, j = 0;

	while(s[i] != '\0')
	{
		switch(s[i])
		{
			case ('\t'):
				t[j++] = '\\';
				t[j++] = 't';
				++i;
				break;

			case ('\n'):
				t[j++] = '\\';
				t[j++] = 'n';
				++i;
				break;

			default:
				t[j++] = s[i++];
				break;
		}
	}
	t[j] = '\0';
}

void de_escape(char s[], char t[])
{
	int i = 0, j = 0;

	while(s[i] != '\0')
	{
		if (s[i] == '\\')
			switch (s[i+1])
			{
				case 'n':
					t[j++] = '\n';
					i += 2;
					break;

				case 't':
					t[j++] = '\t';
					i += 2;
					break;

				default:
					t[j++] = s[i++];
					break;
			}
		else
			t[j++] = s[i++];
	}
	t[j] = '\0';
}

int main()
{
	char s[] = "Hello\t, my name is Harsh\nThis is \t a string\n";
	char t[STR_LEN];

	printf("%s\n", s);
	escape(s, t);
	printf("%s\n\n", t);

	de_escape(t, s);
	printf("%s\n", s);

	return 0;
}
