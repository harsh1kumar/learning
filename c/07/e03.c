/*
 * minprintf: minimal printf
 */

#include <stdio.h>
#include <stdarg.h>

void minprintf(char * fmt, ...);

int main()
{
	minprintf("This is a char : %c :\n"
	       "This is a string: %s :\n"
		, 'r', "Hello World");

	minprintf("This is a char : %3c :\n"
	       "This is a string: %-15s :\n"
		, 'r', "Hello World");

	minprintf("This is an integer: %d :\n"
		"This is an unsigned integer: %u :\n"
		"This is a hex: 0x%x :\n"
		"This is a big hex: 0X%X :\n"
		"This is a oct: 0%o :\n"
		, -534, 534, 0x1A, 0x1A, 056);

	minprintf("This is a double: %f :\n"
		"This is an exp: %e :\n"
		"This is a big exp: %E :\n"
		, 43.2332, 43.2332, 43.2332);

	minprintf("This is a pointer: %p :\n", minprintf);

	minprintf("This is a double: %0.2f :\n", 43.2332);

	return 0;
}

/* A minimal printf */
void minprintf(char * fmt, ...)
{
	va_list ap;
	char * p;
	char spaces[10];
	char my_fmt[10];
	
	/* For args */
	int ival;
	char cval;
	double dval;
	char * sval;
	void * pval;

	va_start(ap, fmt);

	for( ; *fmt; ++fmt)
	{
		if (*fmt != '%')
			putchar(*fmt);
		else
		{
			p = fmt;

			/* Find out any number for spaces/width */
			int i = 0;
			if (*(p+1) == '-')
				spaces[i++] = *++p;

			while (isdigit(*++p))
				spaces[i++] = *p;

			if (*p == '.')
			{
				spaces[i++] = *p;
				while (isdigit(*++p))
					spaces[i++] = *p;
			}
			spaces[i] = '\0';

			sprintf(my_fmt, "%%%s%c", spaces, *p);

			switch (*p)
			{
				case 'c':
					/* Cast is required. See example in man pages */
					cval = (char) va_arg(ap, int);
					printf(my_fmt, cval);
					fmt = p;
					break;

				case 'd': case'i': case 'x': case 'X': case 'o': case 'u':
					ival = va_arg(ap, int);
					printf(my_fmt, ival);
					fmt = p;
					break;

				case 'f': case 'e': case 'E':
					dval = va_arg(ap, double);
					printf(my_fmt, dval);
					fmt = p;
					break;

				case 's':
					sval = va_arg(ap, char *);
					printf(my_fmt, sval);
					fmt = p;
					break;

				case 'p':
					pval = va_arg(ap, void *);
					printf(my_fmt, pval);
					fmt = p;
					break;

				default:
					putchar(*fmt);
					break;
			}
		}
	}

	va_end(ap);
}
