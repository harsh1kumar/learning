/*
 * day_of_year() & month_day()
 */

#include <stdio.h>

int day_of_year(int year, int month, int day);
void month_day(int year, int day, int * month, int * mday);

int main()
{
	printf("%d\n", day_of_year(1900, 12, 31));

	int d, m;
	month_day(2000, 366, &m, &d);
	printf("dd = %d, mm = %d\n", d, m);

	return 0;
}

int monthly_days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int day_of_year(int year, int month, int day)
{
	if (month < 1 || month > 12)
	{
		fprintf(stderr, "Incorrect month\n");
		return 0;
	}
	if (day < 1 ||  day > monthly_days[month-1])
	{
		fprintf(stderr, "Incorrect day of the month\n");
		return 0;
	}

	/* For Feb in a leap year */
	if (year%4 == 0 && year%100 != 0 || year%400 == 0)
		monthly_days[1] = 29;
	else
		monthly_days[1] = 28;

	while(--month)
		day += monthly_days[month-1];

	return day;
}

void month_day(int year, int day, int * month, int * mday)
{
	if (day < 1 || day > 366)
	{
		fprintf(stderr, "Incorrect day\n");
		*month = *mday = 0;
		return;
	}

	/* For Feb in a leap year */
	/* For Feb in a leap year */
	if (year%4 == 0 && year%100 != 0 || year%400 == 0)
		monthly_days[1] = 29;
	else
		monthly_days[1] = 28;

	for(*month=1; day - monthly_days[*month-1] > 0; ++*month)
		day -= monthly_days[*month-1];

	*mday = day;
}



