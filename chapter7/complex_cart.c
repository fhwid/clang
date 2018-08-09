#include <stdio.h>
#include <math.h>

struct complex_struct {double x,y;};

double real_part(struct complex_struct z)
{
	return z.x;
}

double img_part(struct complex_struct z)
{
	return z.y;
}

double magnitude(struct complex_struct z)
{
	return sqrt(z.x * z.x + z.y * z.y);
}

double angle(struct complex_struct z)
{
	return atan2(z.y, z.x);
}

struct complex_struct make_from_real_img(double x, double y)
{
	struct complex_struct z;
	z.x = x;
	z.y = y;
	return z;
}

struct complex_struct make_from_mag_ang(double r, double A)
{
	struct complex_struct z;
	z.x = r * cos(A);
	z.y = r * sin(A);
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
	if (z.y > 0)
		printf("The complex value is %f+%fi\n", z.x, z.y);
	else if (z.y == 0)
		printf("The complex value is %f\n", z.x);
	else
		printf("The complex value is %f%fi\n", z.x, z.y);
}

int main(void)
{
	struct complex_struct z1, z2, z3, z4, z5, z6, z7, z8;
	z1.x = 1, z1.y = 2;
	z2.x = 3, z2.y = 4;
	z3.x = 5, z3.y = 6;
	z4.x = 7, z4.y = 8;
	z5 = add_complex(z1, z2);
	z6 = sub_complex(z1, z2);
	z7 = mul_complex(z3, z4);
	z8 = div_complex(z3, z4);
	print(z5);
	print(z6);
	print(z7);
	print(z8);
	return 0;
}
