/*
 * my_itoa(n, s): integer to aplha/string
 */

#include <stdio.h>
#include <math.h>
#include "reverse.h"

#define STR_LEN 100

void my_itoa(int n, char s[])
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

	s[i] = '\0';

	reverse(s);
}

int main()
{
	char s[STR_LEN];
	
	my_itoa(145, s);
	printf("145: %s\n", s);

	my_itoa(-469, s);
	printf("-469: %s\n", s);

	my_itoa(0, s);
	printf("0: %s\n", s);

	my_itoa(8, s);
	printf("8: %s\n", s);

	my_itoa(5555, s);
	printf("5555: %s\n", s);

	int test = -(pow(2, (sizeof(int)*8)-1));
	my_itoa(test, s);
	printf("%d: %s\n", test, s);

	return 0;
}
