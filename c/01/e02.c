#include "stdio.h"

/*
 * Escape sequences
 */

int main()
{
	printf("\c\d\g\h\i\j\k\l\m\o\p\q\s\w\y\z  \n"); /* Cause warnings */

	printf("\\a : Beep\n");
	printf("\\b : Backspace\n");
	printf("\\e : Escape Character - Non standard extension by GCC\n");
	printf("\\f : Formfeed - Printer ejects the current page and continues printing at the top of another.\n");
	printf("\\r : Carriage Return\n");
	printf("\\v : Vertical tab\n");
	printf("\\uhhhh : Unicode character\n");
	printf("\\xhh : Hexadecimal representation\n");
	printf("\\0nnn : Octal representation\n");
	
	return 0;
}
