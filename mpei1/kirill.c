#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
int kirill() {
	double x, y;
	printf("Enter x: ");
	scanf_s("%lf", &x);
	if ((x <= 0) || (x > 1))
	{
		printf("Not available");
	}
	else
	{
		y = (pow(log(x) * log(x), 1.0 / 3.0) + tan(cos(M_PI * x))) * fabs(log(x / 10.5));
		printf("Result at x=%.2f y=%.5f\n", x, y);
	}
	return 0;
}
