#include <stdio.h>
#include <math.h>

double distance(double x1, double x2, double y1, double y2);
double area(double radius);
double area_point(double x1, double x2, double y1, double y2);

int main(void)
{
	double x1 = 1.0, x2 = 4.0, y1 = 2.0, y2 = 6.0;
	printf("The area is %f.\n", area_point(x1, x2, y1, y2));
	return 0;
}

double distance(double x1, double x2, double y1, double y2)
{
	double dx = x1 - x2;
	double dy = y1 - y2;
	double dist = sqrt(dx * dx + dy * dy);
	return dist;
}

double area(double radius)
{
	double area = 3.1416 * radius * radius;
	return area;
}

double area_point(double x1, double x2, double y1, double y2)
{
	return area(distance(x1, x2, y1, y2));
}


