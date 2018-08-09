#include <math.h>

void print_logarithm(double x)
{
	if (x <= 0.0) {
		printf("Positive number only, please.\n");
			return;
	}
	printf("The log of x is %f", log(x));
}

int is_even(int x)
{
	return !(x % 2);
}

