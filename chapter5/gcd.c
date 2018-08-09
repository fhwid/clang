#include <stdio.h>

int gcd(int, int);

int main(void)
{
	int a = 400, b = 250;
	int c = gcd(a, b);
	printf("The gcd of %d and %d is %d.\n", a, b, c);
	return 0;
}

int gcd(int a, int b)
{
	if (a % b == 0)
		return b;
	else {
		int c = gcd(b, a % b);
		return c;
	}
}

