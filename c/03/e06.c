/*
 * my_itoa(n, s, w): integer to aplha/string with width w
 */

#include <stdio.h>
#include <math.h>
#include "reverse.h"

#define STR_LEN 100

void my_itoa(int n, char s[], int w)
{
	int sign;
	int i=0;

	sign = (n < 0) ? -1 : 1; /* Save sign */
	n *= sign; /* Make +ve */

	do
	{
		s[i++] = abs(n%10) + '0';
	} while((n /= 10));

	if (sign == -1)
		s[i++] = '-';

	/* Adding extra spaces if required */
	while (i<w)
		s[i++] = ' ';

	s[i] = '\0';

	reverse(s);
}

int main()
{
	char s[STR_LEN];
	int i, j;

	for (i=2; i<6; ++i)
	{
		printf("Width = %d: ", i);
		for (j=-111; j<100; j+=9)
		{
			my_itoa(j, s, i);
			printf("%s|", s);
		}
		printf("\n\n\n");
	}

	return 0;
}
 
