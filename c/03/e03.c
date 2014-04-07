/*
 * expand(s1, s2): expand shorthands like a-z in s1 to complete abc...xyz in s2
 */

#include <stdio.h>
#include <ctype.h>

#define S2_SIZE 1000

#define TRUE 1
#define FALSE 0

void expand(char s1[], char s2[])
{
	int i = 0, j = 0;
	char left, right;
	int do_expand = FALSE;

	s2[j++] = s1[i++];
	while(s1[i] != '\0')
	{
		do_expand = FALSE;
		if (s1[i] == '-')
		{
			left = s2[j-1];
			right = s1[i+1];
			
			if (isdigit(left) && isdigit(right))
				do_expand = TRUE;
			else if (isalpha(left) && isalpha(right))
			{
				if (isupper(left) && isupper(right))
					do_expand = TRUE;
				else if (islower(left) && islower(right))
					do_expand = TRUE;
			}
		}
		if (do_expand)
		{
			i += 2; /* i incremented by 2 as '-' & right are also copied */
			if (left < right)
			{
				while(left < right)
					s2[j++] = ++left;
			}
			else if (left > right)
			{
				while(left > right)
					s2[j++] = --left;
			}
			else
				; /* left & right are equal, no need to do anything as i already incremented by 2 */
		}
		else
			s2[j++] = s1[i++];
	}
	s2[j] = '\0';
}

int main()
{
	char s1[] = "--a-z-0-9-AHa---rsh-A-B-C--";
	char s2[S2_SIZE];

	expand(s1, s2);
	printf("%s : %s\n", s1, s2);

	return 0;
}

