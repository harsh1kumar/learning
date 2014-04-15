/*
 * minscanf: minimal scanf
 */

#include <stdio.h>
#include <stdarg.h>

int minscanf(char * fmt, ...);

int main()
{
	int i, ret;
	ret = minscanf("A int: %d", &i);
	if (ret == 1)
		printf("\n-->%d\n", i);
	else 
		printf("\nRet = %d\n", ret);
	return 0;
}

/* A minimal scanf */
int minscanf(char * fmt, ...)
{
	va_list ap;
	int ch;
	int items;
	int ret;
	char my_fmt[10];
	
	/* For args */
	int * ip;
	char *cp;
	double * dp;
	char ** sp;
	void ** pp;

	va_start(ap, fmt);
	items = 0;
	for( ; *fmt; ++fmt)
	{
		if (isspace(*fmt))
		{
			while(isspace(ch=getchar()));
				;
			ungetc(ch, stdin);
			continue;
		}

		if (*fmt != '%')
		{
			if ((ch=getchar()) != *fmt)
				return items;
		}
		else
		{
			sprintf(my_fmt, "%%%c", *(fmt+1));

			switch (*(fmt+1))
			{
				case 'c':
					/* Cast is required. See example in man pages */
					cp = (char *) va_arg(ap, int *);
					ret = scanf(my_fmt, cp);
					if (ret) ++items; else return items;
					++fmt;
					break;

				case 'd': case'i': case 'x': case 'o': case 'u':
					ip = va_arg(ap, int *);
					ret = scanf(my_fmt, ip);
					if (ret) ++items; else return items;
					++fmt;
					break;

				case 'f': case 'e': case 'E':
					dp = va_arg(ap, double *);
					ret = scanf(my_fmt, dp);
					if (ret) ++items; else return items;
					++fmt;
					break;

				case 's':
					sp = va_arg(ap, char **);
					ret = scanf(my_fmt, sp);
					if (ret) ++items; else return items;
					++fmt;
					break;

				case 'p':
					pp = va_arg(ap, void **);
					ret = scanf(my_fmt, pp);
					if (ret) ++items; else return items;
					++fmt;
					break;

				default:
					if ((ch=getchar()) != *fmt)
						return items;
					break;
			}
		}
	}

	va_end(ap);
	return items;
}
