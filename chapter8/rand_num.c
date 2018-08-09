#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 200 

int a[N];
int histogram[10] = {0};
void gen_random(int upper_bound)
{
	int i;
	srand(time(NULL));
	for (i = 0; i < N; i++)
		a[i] =  rand() % upper_bound;
}

int howmany(int value)
{
	int count = 0, i;
	for (i = 0; i < N; i++)
		if (a[i] ==value)
			++count;
	return count;
}

void print_random()
{
	int i;
	for (i = 0; i < N; i++)
		printf("%d ", a[i]);
	printf("\n");
}

void print_hist()
{
	int i, j, k;
	for (i = 0; i < 10; i++)
		printf("%d\t", i);
	printf("\n");
	j = 0;
	while (j < N) {
		for (k = 0; k < 10; k++) {
			if (histogram[k] != 0) {
				printf("*\t");
				histogram[k]--;
				j++;
			}
			else
				printf("\t");
		}
		printf("\n");
	}
}

int main(void)
{
	int i;
	gen_random(10);
	for (i = 0; i < N; i++)
		histogram[a[i]]++;
	print_hist();
	return 0;
}
