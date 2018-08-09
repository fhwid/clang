#include <stdio.h>
#include <math.h>

#define PI 3.1415926

enum coordinate_type {RECTANGULAR, POLAR};
struct complex_struct {
	enum coordinate_type t;
	double x,y;
};

double real_part(struct complex_struct z)
{
	if (z.t == RECTANGULAR)
		return z.x;
	else
		return z.x * cos(z.y);
}

double img_part(struct complex_struct z)
{
	if (z.t == RECTANGULAR)
		return z.y;
	else
		return z.x * sin(z.y);
}

double magnitude(struct complex_struct z)
{
	if (z.t == RECTANGULAR)
		return sqrt(z.x * z.x + z.y * z.y);
	else
		return z.x;
}

double angle(struct complex_struct z)
{
	if (z.t == RECTANGULAR)
		return atan2(z.y, z.x);
	else
		return z.y;
}

struct complex_struct make_from_real_img(double x, double y)
{
	struct complex_struct z;
	z.x = x;
	z.y = y;
	z.t = RECTANGULAR;
	return z;
}

struct complex_struct make_from_mag_ang(double r, double A)
{
	struct complex_struct z;
	z.x = r;
	if (fabs(A) < PI)
		z.y = A;
	else if (A > 0)
		z.y = fmod(A, PI) - PI;
	else
		z.y = fmod(A, PI) + PI;
	z.t = POLAR;
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
	if (z.t == RECTANGULAR)
	{
		if (z.y > 0)
			printf("The complex value is %f+%fi\n", z.x, z.y);
		else if (z.y == 0)
			printf("The complex value is %f\n", z.x);
		else
			printf("The complex value is %f%fi\n", z.x, z.y);
	}
	else
	{
		printf("The complex value is %fe^i%fPI.\n", z.x, z.y / PI);
	}
}

int main(void)
{
	struct complex_struct z1, z2, z3, z4, z5, z6, z7, z8;
	z1.x = 1, z1.y = 2, z1.t = RECTANGULAR;
	z2.x = 3, z2.y = 4, z2.t = RECTANGULAR;
	z3.x = 5, z3.y = 6, z3.t = RECTANGULAR;
	z4.x = 7, z4.y = 8, z4.t = RECTANGULAR;
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
