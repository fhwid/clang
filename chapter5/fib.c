#include <stdio.h>

int fib(int);

int main(void)
{
	int n = 2;
	int m = fib(n);
	printf("%d:%d\n", n, m);
	return 0;
}

int fib(int n)
{
	if (n == 0 || n == 1)
		return 1;
	else {
		int m = fib(n - 1) + fib(n - 2);
		return m;
	}
}

