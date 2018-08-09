#include <stdio.h>
struct complex_struct {double x, y;};
struct complex_struct add_complex(struct complex_struct z1, struct complex_struct z2);

int main(void)
{
	struct complex_struct z1, z2, z3;
	z1.x = 3.0;
	z1.y = 4.0;
	z2 = z1;
	z3 = add_complex(z1, z2);
	printf("z3 = %f + %fi\n", z3.x, z3.y);
	return 0;
}

struct complex_struct add_complex(struct complex_struct z1, struct complex_struct z2)
{
	z1.x = z1.x + z2.x;
	z1.y = z1.y + z2.y;
	return z1;
}
