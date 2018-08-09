#include <stdio.h>

int is_leap_year(int);

int main(void)
{
	int x = 2009;
	if (is_leap_year(x))
		printf("%d is a leap year.\n", x);
	else
		printf("%d is not a leap year.\n", x);
	return 0;
}

int is_leap_year(int year)
{
	if ((year % 400) == 0)
		return 1;
	else if (((year % 4) == 0) && ((year % 100) != 0))
		return 1;
	else
		return 0;
}

