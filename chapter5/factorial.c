#include <stdio.h>

int factorial(int);

int main(void)
{
	int i = 12, j = 3;
	printf("The factorial of %d is %d.\n", i, factorial(i));
	printf("The factorial of %d is %d.\n", j, factorial(j));
	return 0;
}

int factorial(int n)
{
	if (n == 0)
		return 1;
	else {
		int result = n * factorial(n - 1);
		return result;
	}
}

