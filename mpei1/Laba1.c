#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
int laba1() {
	double x, y, y1, y2;
	printf("Введите число: ");
	scanf_s("%lf", &x);
	if (x < 0 || x > M_PI)
	{
		printf("Bad number");
	}
	else
	{
		y1 = 1.0 / 3.0 * sqrt(fabs(sin(x)));
		y2 = cbrt(exp(0.12 * x));
		y = y1 * y2;
		printf("Result at x=%.2f  y=%.5f ", x,y); // исправить фразу на вывод
	}
	return 0;
}

