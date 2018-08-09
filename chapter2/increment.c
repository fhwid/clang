#include <stdio.h>

int increment(int);

int main(void)
{
	int i = 1, j = 2;
	i = increment(i);
	j = increment(j);
	printf("%d,%d\n", i, j);
	return 0;
}

int increment(int x)
{
	x = x + 1;
	return x;
}


