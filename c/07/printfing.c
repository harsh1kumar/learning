/*
 * Printfing
 */

#include <stdio.h>

int main()
{
	printf(":%d:\n", 1000);		// :1000:
	printf(":%-d:\n", 1000);	// :1000:
	printf(":%3d:\n", 1000);	// :1000:
	printf(":%6d:\n", 1000);	// :  1000:
	printf(":%-3d:\n", 1000);	// :1000:
	printf(":%-6d:\n", 1000);	// :1000  :
	printf(":%.1d:\n", 1000);	// :1000:
	printf(":%.6d:\n", 1000);	// :001000:	precision = min no of digits in a integer
	printf(":%hd:\n", 100000);	// NOT:100000:		h prints short int
	printf(":%ld:\n", 100000);	// :100000:		l prints long int

	printf("\n");
	printf(":%i:\n", 1000);		// :1000:	%i same as %d
	printf(":%u:\n", 1000);		// :1000:	Unsigned integer
	
	printf("\n");
	printf(":%f:\n", 10.0);		// :10.000000:	default precision is 6
	printf(":%.2f:\n", 10.0);	// :10.00:

	printf("\n");
	printf(":%e:\n", 10.0001);	// :1.000010e+1:
	printf(":%E:\n", 10.0001);	// :1.000010E+1:
	printf(":%g:\n", 0.00001);	// :1e-5:	prints %e if exponent is less than -4
	printf(":%G:\n", 0.00001);	// :1E-5:	prints %E if exponent is less than -4
	printf(":%g:\n", 10.10);	// :10.1:	trailing 0 not printed
	printf(":%g:\n", 10.);		// :10:		trailing decimal point not printed

	char * s = "Hello world";
	printf(":%s:\n", s);		// :Hello world:
	printf(":%10s:\n", s);		// :Hello world:
	printf(":%15s:\n", s);		// :    Hello world:
	printf(":%-15s:\n", s);		// :Hello world    :
	printf(":%.15s:\n", s);		// :Hello world:
	printf(":%.8s:\n", s);		// :Hello wo:	precision sets maximum digits to be printed

	return 0;
}






