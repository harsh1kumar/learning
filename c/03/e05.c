/*
 * my_itob(n,s,b): covert 'n' into base 'b' representation in 's'
 */

#include <stdio.h>
#include "reverse.h"

#define STR_LEN 100

void my_itob(int n, char s[], int b)
{
	int i=0;
	int rem;
	int sign;

	sign = (n<0) ? -1 : 1; /* Save sign */
	n *= sign; /* Make +ve */

	do
	{
		rem = abs(n%b);
		if (rem >= 0 && rem <=9)
			s[i++] = rem + '0';
		else
			s[i++] = (rem-10) + 'A';
	} while(n /= b);

	if (sign == -1)
		s[i++] = '-';
	s[i] = '\0';

	reverse(s);
}

int main()
{
	char s[STR_LEN];

	int i, j;
	for (j=2; j<20; ++j)
	{
		printf("Base %d: ", j);
		for(i=-10; i<20; ++i)
		{
			my_itob(i, s, j);
			printf("%s ", s);
		}
		printf("\n");
	}

	return 0;
}
