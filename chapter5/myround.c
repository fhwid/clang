#include <stdio.h>
#include <math.h>

double myround(double x);

int main(void)
{
	double x = -3.1415926;
	double y = -5.9;
	double r_x = myround(x);
	double r_y = myround(y);
	printf("%f:%f, %f:%f\n", x, r_x, y, r_y);
	return 0;
}

double myround(double x)
{
	if (fabs(x - ceil(x)) <= 0.5)
		return ceil(x);
	else
		return floor(x);
}

