#include <stdio.h>
#include <math.h>

struct rational {int x, y;};

int numerator(struct rational z)
{
	return z.x;
}

int denominator(struct rational z)
{
	return z.y;
}

int gcd(int x, int y)
{
	if (x % y == 0)
		return y;
	else
		return gcd(y, x % y);
}

struct rational make_from_nume_demo(int x, int y)
{
	struct rational z = {0, 0};
	if (y == 0)
	{
		printf("error01\n");
		return z;
	}		
	else
	{
		int c = gcd(x, y);
		struct rational z;
		z.x = x / c;
		z.y = y / c;
		return z;
	}
}

struct rational add_rational(struct rational z1, struct rational z2)
{
	return make_from_nume_demo(z1.x * z2.y + z2.x * z1.y, z1.y * z2.y);
}

struct rational sub_rational(struct rational z1, struct rational z2)
{
	return make_from_nume_demo(z1.x * z2.y - z2.x * z1.y, z1.y * z2.y);
}

struct rational mul_rational(struct rational z1, struct rational z2)
{
	return make_from_nume_demo(z1.x * z2.x, z1.y * z2.y);
}

struct rational div_rational(struct rational z1, struct rational z2)
{
	return make_from_nume_demo(z1.x * z2.y, z1.y * z2.x);
}

void print(struct rational z)
{
	if (z.y == 0)
		printf("number error!\n");
	else if (z.y == 1)
		printf("The rational number is %d.\n", z.x);
	else if (z.x == 0)
		printf("The rational number is 0.\n");
	else
		printf("The rational number is %d/%d.\n", z.x, z.y);
}

int main(void)
{
	struct rational a = make_from_nume_demo(1, 8);
	struct rational b = make_from_nume_demo(-1, 8);
	print(add_rational(a, b));
	print(sub_rational(a, b));
	print(mul_rational(a, b));
	print(div_rational(a, b));
	return 0;
}
