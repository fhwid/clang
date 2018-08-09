#include <stdio.h>
#include <math.h>

struct complex_struct {double r, A;};

double real_part(struct complex_struct z)
{
	return z.r * cos(z.A);
}

double img_part(struct complex_struct z)
{
	return z.r * sin(z.A);
}

double magnitude(struct complex_struct z)
{
	return z.r;
}

double angle(struct complex_struct z)
{
	return z.A;
}

struct complex_struct make_from_real_img(double x, double y)
{
	struct complex_struct z;
	z.r = sqrt(x * x + y * y);
	z.A = atan2(y, x);
	return z;
}

struct complex_struct make_from_mag_ang(double r, double A)
{
	struct complex_struct z;
	z.r = r;
	z.A = A;
	return z;
}

struct complex_struct add_complex(struct complex_struct z1, struct complex_struct z2)
{
	return make_from_real_img(real_part(z1) + real_part(z2), img_part(z1) + img_part(z2));
}

struct complex_struct sub_complex(struct complex_struct z1, struct complex_struct z2)
{

	return make_from_real_img(real_part(z1) - real_part(z2), img_part(z1) - img_part(z2));
}

struct complex_struct mul_complex(struct complex_struct z1, struct complex_struct z2)
{
	return make_from_mag_ang(magnitude(z1) * magnitude(z2), angle(z1) + angle(z2));
}

struct complex_struct div_complex(struct complex_struct z1, struct complex_struct z2)
{
	return make_from_mag_ang(magnitude(z1) / magnitude(z2), angle(z1) - angle(z2));
}

void print(struct complex_struct z)
{
	printf("The complex value is %fe^%f.\n", z.r, z.A);
}

int main(void)
{
	struct complex_struct z1, z2, z3, z4, z5, z6, z7, z8;
	z1.r = 1, z1.A = 3.1416 / 2;
	z2.r = 1, z2.A = 3.1416 / 2;
	z3.r = 2, z3.A = 3.1416 / 2;
	z4.r = 2, z4.A = 3.1416 / 2;
	z5 = add_complex(z1, z2);
	z6 = sub_complex(z1, z2);
	z7 = mul_complex(z3, z4);
	z8 = div_complex(z3, z4);
	print(z5);
	print(z6);
	print(z7);
	print(z8);
	printf("%f\n", angle(z8));
	return 0;
}
