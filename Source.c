#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

double getRandomNumber(const double min, const double max)
{
	double temp = (double)rand() / (double)RAND_MAX;

	temp = min + (max - min)*temp;

	return temp;
}

bool isInsideCircle(const double x, const double y)
{
	const double x_c = 0.5;
	const double y_c = 0.5;
	const double r = 0.5;

	const double f = (x - x_c)*(x - x_c) + (y - y_c)*(y - y_c) - r*r;

	if (f > 0.0) return false;
	else return true;
}

bool isInsideCircle2(const double a, const double y) //�ι�°��
{
	const double x_c = 2.5;
	const double y_c = 0.5;
	const double r = 0.5;

	const double f = (a - x_c)*(a - x_c) + (y - y_c)*(y - y_c) - r*r;

	if (f > 0.0) return false;
	else return true;
}

void main()
{
	FILE *of = fopen("circle.txt", "w");

	srand((unsigned int)time(NULL));

	for (int i = 0; i < 10000; i++)
	{
		double x = getRandomNumber(0.0, 1.0);
		double y = getRandomNumber(0.0, 1.0);
		double a = getRandomNumber(2.0, 3.0);
		double b = getRandomNumber(1.0, 2.0);
		double c = getRandomNumber(0.3, 0.7);
		fprintf(of, "%f, %f\n", b, c);

		if (isInsideCircle(x, y) == true)
		{
			fprintf(of, "%f, %f\n", x, y);
		}
		if (isInsideCircle2(a, y) == true)
		{
			fprintf(of, "%f, %f\n", a, y);
		}
	}

	fclose(of);
}