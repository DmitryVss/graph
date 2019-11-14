#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <conio.h>

#pragma warning(disable:4996)

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
double findExtremum(double a, double b, char c)
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
void Graphics(double A, double B, int rangeX, int rangeY, double yMax, double yMin)
{
	double scaleX, scaleY, y, x, epsY, epsX;

	scaleX = scale(A, B, rangeX);
	scaleY = scale(yMin, yMax, rangeY);
	epsY = scaleY / 2;
	epsX = scaleX / 2;
	printf("\n\tGRAPHICS\n");
	for (y = yMax; y >= yMin - scaleY; y -= scaleY)
	{
		printf("\t");
		for (x = A; x <= B; x += scaleX)
		{
			if (fabs(y - f(x)) <= epsY)
				printf("*");
			else if (fabs(y) <= epsY && fabs(y - f(x)) > epsY)
				printf("%c", 196);
			else if (fabs(x) <= epsX && fabs(y - f(x)) > epsY)
				printf("%c", 179);
			else
				printf(" ");
		}
		printf("\n");
	}
}
void Gistogramma(double A, double B, int rangeX, int rangeY, double yMax, double yMin)
{
	FILE *fout;
	fout = fopen("Resulte.txt", "w");
	double scaleX, scaleY, y, yNow, x, eps = 0.03;
	int i, flag;
	scaleX = scale(A, B, rangeX);
	scaleY = scale(yMin, yMax, rangeY);
	eps = scaleY / 2;
	printf("\n\n\tGISTOGRAMMA\n\t");
	fprintf(fout, "\n\n\tGISTOGRAMMA\n\t");
	for (i = -10, y = yMin - 10 * scaleY; i <= rangeY + 10; i++, y += scaleY)
	{
		if (i % 10 == 0)
		{
			if (fabs(y) < eps)
			{
				printf("0.000");
				fprintf(fout, "0.000");
			}
			else
			{
				printf("%2.3lf", y);
				fprintf(fout, "%2.3lf", y);
			}

			if (y < 0)
			{
				i += 5;
				y += 5 * scaleY;
			}
			else
			{
				i += 4;
				y += 4 * scaleY;
			}
		}
		else
		{
			printf(" ");
			fprintf(fout, " ");
		}
	}
	printf("\n\t");
	fprintf(fout, "\n\t");
	for (i = -10; i <= rangeY + 10; i++)
	{
		if (i % 10 == 0)
		{
			printf("%c", 197);
			fprintf(fout, "+");
		}
		else
		{
			printf("%c", 196);
			fprintf(fout, "-");
		}
	}

	printf("\n");
	fprintf(fout, "\n");
	for (x = A; x <= B; x += scaleX)
	{
		flag = 1;
		printf("\t");
		fprintf(fout, "\t");
		yNow = Func(x);
		if (yNow > 0)
		{
			for (y = yMin - 10 * scaleY; y <= yMax + 10 * scaleY; y += scaleY)
			{

				if (y < -eps)
				{
					printf(" ");
					fprintf(fout, " ");
				}
				else if (fabs(y) <= eps)
				{
					printf("%c", 179);
					fprintf(fout, "|");
				}
				else if (y > 0 && y <= yNow + eps)
				{
					printf("*");
					fprintf(fout, "*");
				}
				else if (y > yNow && flag)
				{
					printf(" %2.4lf", yNow);
					fprintf(fout, " %2.4lf", yNow);
					y += 7 * scaleY;
					flag = 0;
				}
				else
				{
					printf(" ");
					fprintf(fout, " ");
				}
			}
			printf("\n");
			fprintf(fout, "\n");
		}
		else
		{
			for (y = yMin - 10 * scaleY; y <= yMax + 10 * scaleY; y += scaleY)
			{

				if (y < 0 && y < yNow - 8 * scaleY)
				{
					printf(" ");
					fprintf(fout, " ");
				}
				else if (y > yNow - 8 * scaleY && flag)
				{
					printf("%2.4lf ", yNow);
					fprintf(fout, "%2.4lf ", yNow);
					y += 7 * scaleY;
					flag = 0;
				}
				else if (y < 0 && y >= yNow)
				{
					printf("*");
					fprintf(fout, "*");
				}
				else if (fabs(y) <= eps)
				{
					printf("%c", 179);
					fprintf(fout, "|");
				}
				else
				{
					printf(" ");
					fprintf(fout, " ");
				}
			}
			printf("\n");
			fprintf(fout, "\n");
		}
	}
	fclose(fout);
}
int main()
{
	int cwith = 78;
	int cheigth = 25;
	int fwith = 60;
	int fheigth = 80;
	double a = -1;
	double b = 4;
	double min = findExtremum(a, b, 'n');
	double max = findExtremum(a, b, 'x');

	Graphics(a, b, cwith, cheigth, max, min);
	Gistogramma(a, b, fwith, fheigth, max, min);
	system("pause");
	return 0;
}