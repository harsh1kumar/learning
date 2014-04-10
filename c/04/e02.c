/*
 * my_atof(s): Return floating point number of string s which is in scientific notation
 */

#include <stdio.h>
#include <string.h>

double my_pow(int num, int power);
double my_atof(char s[]);

int main()
{
	printf("%f\n", my_atof("123"));
	printf("%f\n", my_atof("+123"));
	printf("%f\n\n", my_atof("-123"));

	printf("%f\n", my_atof("0"));
	printf("%f\n", my_atof("1"));
	printf("%f\n", my_atof(" 123"));
	printf("%f\n\n", my_atof("   123"));

	printf("%f\n", my_atof("123.45"));
	printf("%f\n", my_atof("+123.45"));
	printf("%f\n\n", my_atof("-123.45"));

	printf("%f\n", my_atof("123e6"));
	printf("%f\n", my_atof("+123e6"));
	printf("%f\n\n", my_atof("-123e6"));

	printf("%f\n", my_atof("123e+6"));
	printf("%f\n", my_atof("+123e+6"));
	printf("%f\n\n", my_atof("-123e+6"));

	printf("%f\n", my_atof("123e-6"));
	printf("%f\n", my_atof("+123e-6"));
	printf("%f\n\n", my_atof("-123e-6"));

	printf("%f\n", my_atof("123.45e6"));
	printf("%f\n", my_atof("+123.45e6"));
	printf("%f\n\n", my_atof("-123.45e6"));

	printf("%f\n", my_atof("123.45e+6"));
	printf("%f\n", my_atof("+123.45e+6"));
	printf("%f\n\n", my_atof("-123.45e+6"));

	printf("%.10f\n", my_atof("123.45e-6"));
	printf("%.10f\n", my_atof("+123.45e-6"));
	printf("%.10f\n\n", my_atof("-123.45e-6"));

	return 0;
}

double my_pow(int num, int power)
{
	if (power == 0)
		return 1;
	else if (power == 1)
		return num;
	else if (power == -1)
		return 1.0/num;
	else if (power > 1)
		return num * my_pow(num, power-1);
	else if (power < -1)
		return (1.0/num) * my_pow(num, power+1);
	else
		printf("Power Error\n");
}

double my_atof(char s[])
{
	int i=0;
	int sign;

	for (i=0; isspace(s[i]); ++i)
		;

	/* Find & save sign */
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '-' || s[i] == '+')
		++i;

	double retval=0;
	/* Evaluation of integer part */
	for (retval=0; isdigit(s[i]); ++i)
		retval = retval*10 + s[i] - '0';

	long int power=1;
	/* Evaluation of fractional part */
	if (s[i] == '.')
	{
		for (++i; isdigit(s[i]); ++i)
		{
			retval = retval*10 + s[i] - '0';
			power *= 10;
		}
	}

	int exp=0;
	/* Evaluation of exponential part */
	if (s[i]=='e' || s[i]=='E')
	{
		++i;

		/* Find sign of exponential part */
		int exp_sign;
		exp_sign = (s[i] == '-') ? -1 : 1;
		if (s[i] == '-' || s[i] == '+')
			++i;

		for (exp=0; isdigit(s[i]); ++i)
			exp = exp*10 + s[i] - '0';

		exp *= exp_sign;
	}

	return sign * (retval / power) * my_pow(10, exp);
	
}

