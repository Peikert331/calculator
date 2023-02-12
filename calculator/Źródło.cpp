#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<locale.h>
#include<string.h>
#pragma warning(disable: 4996)
using namespace std;
struct zespolone { double a, b; };
struct zespolone dodawanie(struct zespolone x, struct zespolone y)
{
	struct zespolone z;
	z.a = x.a + y.a;
	z.b = x.b + y.b;
	return z;
}
struct zespolone odejmowanie(struct zespolone x, struct zespolone y)
{
	struct zespolone z;
	z.a = x.a - y.a;
	z.b = x.b - y.b;
	return z;
}
struct zespolone mnozenie(struct zespolone x, struct zespolone y)
{
	struct zespolone z;
	z.a = x.a * y.a - x.b * y.b;
	z.b = x.a * y.b + x.b * y.a;
	return z;
}
struct zespolone dzielenie(struct zespolone x, struct zespolone y)
{
	struct zespolone z;
	z.a = (x.a * y.a + x.b * y.b) / (pow(y.a, 2) + pow(y.b, 2));
	z.b = (x.b * y.a - x.a * y.b) / (pow(y.a, 2) + pow(y.b, 2));
	return z;
}
int main()
{
	setlocale(LC_ALL, ".852");
	printf(" Kalkulator liczb zespolonych\n\n ");
	double xa, xb, ya, yb;
	int n;
	printf("Podaj czesc rzeczywista pierwszej liczby zespolonej: \n ");
	if (scanf(" %lf", &xa))
	{
		printf(" Podaj czesc urojona pierwszej liczby zespolonej: \n ");
		if (scanf(" %lf", &xb))
		{
			printf(" Podaj czesc rzeczywista drugiej liczby zespolonej: \n ");
			if (scanf(" %lf", &ya))
			{
				printf(" Podaj czesc urojona drugiej liczby zespolonej: \n ");
				if (scanf(" %lf", &yb))
				{
					printf(" Podaj n-ta potege liczby zespolonej: \n ");
					if (scanf(" %d", &n))
					{
						struct zespolone c = { xa,xb }, d = { ya,yb }, e;
						e = dodawanie(c, d);
						printf("\n Suma: %g + %gi\n", e.a, e.b);
						struct zespolone c1 = { xa,xb }, d1 = { ya,yb }, e1;
						e1 = odejmowanie(c1, d1);
						printf(" Roznica: %g + %gi\n", e1.a, e1.b);
						struct zespolone c2 = { xa,xb }, d2 = { ya,yb }, e2;
						e2 = mnozenie(c2, d2);
						printf(" Iloczyn: %g + %gi\n", e2.a, e2.b);
						struct zespolone c3 = { xa,xb }, d3 = { ya,yb }, e3;
						e3 = dzielenie(c3, d3);
						printf(" Iloraz: %g + %gi\n", e3.a, e3.b);
						double modul, kat;
						modul = sqrt(pow(xa, 2) + pow(xb, 2));
						kat = atan2(xb, xa);
						double moduln, katn;
						moduln = pow(modul, n);
						katn = n * kat;
						double e4a, e4b;
						e4a = moduln * cos(katn);
						e4b = moduln * sin(katn);
						printf(" N-ta potega: %g + %gi\n", e4a, e4b);
					}
					else
					{
						printf("\n Blad konwersji liczby.");
					}
				}
				else
				{
					printf("\n Blad konwersji liczby.");
				}
			}
			else
			{
				printf("\n Blad konwersji liczby.");
			}
		}
		else
		{
			printf("\n Blad konwersji liczby.");
		}
	}
	else
	{
		printf("\n Blad konwersji liczby.");
	}
	_getch();
}