#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double f(double x)
{
	double f = x - 3;
	double sum = x * x + 2;
	f = f / sum;
	return f;
}
double scale(double a, double b, double range)
{
	double m = fabs(b - a);
	m = m / range;
	return m;
}
double detsc(double a, double b, char c)
{
	double ext = f(a);
	switch (c)
	{
	case 'x':
		for (int i = 0; i <= b; i++)
			if (ext < f(i)) ext = f(i);
		break;
	case'n':
		for (int i = 0; i <= b; i++)
			if (ext > f(i)) ext = f(i);
		break;
	default:
		break;
	}
	return ext;
}
//void drawgraph(FILE* out, )
//{
//
//}
int main()
{
	//FILE* out = fopen("res.txt", "wt");

	int cwith = 78;
	int cheigth = 25;
	int fwith = 60;
	int fheigth = 80;
	double a = -1;
	double b = 4;
	double x;
	double y;
	double cstep = 1;
	double fstep = abs(b - a) / fwith;
	double min = detsc(a, b, 'n');
	double max = detsc(a, b, 'x');
	double cscale_x = scale(a, b, cwith);
	double cscale_y = scale(min, max, cheigth);
	double fscale_x = scale(a, b, fwith);
	double fscale_y = scale(min, max, fheigth);

	int j;
	x = a;
	while (x <= b)
	{
		y = f(x);
		if (y < 0)
		{
			j = (fheigth / 2);
		}
		else if (y == 0)
		{
			for (int i = 0; i < (fheigth / 2) - 1; i++) fprintf("%c", ' ');
			fprintf("%c% .4d\n", '*', 0);
		}
		else
		{

		}
		x += fstep;
	}

	//fclose(out);
	system("pause");
	return 0;
}