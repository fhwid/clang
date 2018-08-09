#include <stdio.h>

void foo(void);

int main(void)
{
	foo();
	foo();
	return 0;
}

void foo(void)
{
	int i;
	printf("%d\n", i);
	i = 100;
}

