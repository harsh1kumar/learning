#include <stdio.h> 
#include <stdlib.h>

void printline(FILE * f);

int main(int argc, char * argv[])
{
	FILE * f1, * f2;
	char * s1 = NULL, * s2 = NULL;
	int len1=0, len2=0;
	int ret1, ret2;

	f1 = fopen(argv[1], "r");
	f2 = fopen(argv[2], "r");

	if (f1 == NULL || f2 == NULL)
	{
		fprintf(stderr, "Not able to open files\n");
		exit(1);
	}

	while(1)
	{
		ret1 = getline(&s1, &len1, f1);
		ret2 = getline(&s2, &len2, f2);
		if (strcmp(s1, s2))
		{
			printf("%s", s1);
			printf("%s", s2);
			break;
		}
		if (ret1 == EOF || ret2 == EOF)
			break;

		free(s1);
		free(s2);
		s1 = NULL;
		s2 = NULL;
	}

	fclose(f1);
	fclose(f2);
	return 0;
}

void printline(FILE * f)
{
	int c;

	while(1)
	{
		c = getc(f);
		putchar(c);
		if (c == '\n')
			break;
	}
}


