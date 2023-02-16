#include <iostream>
using namespace std;

/* Całkowana funkcja (nie zmieniaj wzoru!): */
double funkcjaMatematyczna(double x)
{
	return 2.0 * x * x + 3.0 * x;
}


double całkowanie(double xp, double xk, double e,int &n)
/* xp - dolna granica, xk - górna granica, n - liczba trapezów */
{

	/* Sprawdź warunki: xk > xp i n > 0. Jesli choć jeden nie jest spełniony przerwij funkcję wynikiem 0 */
	if (xk < xp || n < 0)
	{
		return 0;
	}
	n =2;
	double roznica = 0, pole, PolePop = 0;
	/* Wyznacz wysokość h trapezow jako długość odcinka |xp, xk| podzieloną przez n (liczbę trapezów)*/
	do
	{
		n *= 2;
		double h = fabs(xp - xk) / n;

		/* Ustaw wartość oszacowania całki oznaczonej na 0 */
		pole = 0;
		/* Powtarzaj n razy: */
		for (int i = 0; i < n; i++)
		{
			double fa = funkcjaMatematyczna(xp + i * h);
			double fb = funkcjaMatematyczna(xp + (i + 1) * h);

			/* Wyznacz podstawy trapezów dla i-tej itreacji jako wartości całkowanej funkcji w punktach:
			   a = xp+i*h i b = xp+(i+1)*h, gdzie i to numer iteracji. */
			   /* Wylicz pole trapezu o podstawach f(a), f(b) i wyskosci h, gdzie f() to funkcjaMatematyczna powyżej).*/
			double Pole_trapezu = 0.5 * h * (fa + fb);
			   /* Dodaj wyliczone pole trapezu do aktualnego oszacowania całki */
			pole += Pole_trapezu;
		}
	} while (roznica > e);
	/* Zwroc oszacowanie całki jako wynik funkcji */
	return pole;
}

struct dane
{
	double xp, xk, e,pole;
	int n;
};


void wypelnij(dane& całka, double xp, double xk, const double e, int n )
{
	całka.xp = xp;
	całka.xk = xk;
	całka.n = n;
	całka.e = 0.001;
	całka.pole = całkowanie(xp,xk,e,n);
}

void wypelnij(dane& całka, double xp, double xk)
{
	całka.xp = xp;
	całka.xk = xk;
	całka.pole = całkowanie(xp, xk, całka.e, całka.n);
}

int main()
{
	int n = 0;
	cout << fixed;
	cout << "Calka (n =   5): " << całkowanie(1.0, 2.0, 5,n) << endl;   /* Dla tych danych wynik poprawny to  9.180000 */
	cout << "Calka (n =  20): " << całkowanie(1.0, 2.0, 20, n) << endl;  /* Dla tych danych wynik poprawny to  9.167500 */
	cout << "Calka (n = 200): " << całkowanie(1.0, 2.0, 200, n) << endl; /* Dla tych danych wynik poprawny to  9.166675 */

	cout << "Calka (n =   5): " << całkowanie(1.0, 3.0, 5, n) << endl;   /* Dla tych danych wynik poprawny to 29.440000 */
	cout << "Calka (n =  20): " << całkowanie(1.0, 3.0, 20, n) << endl;  /* Dla tych danych wynik poprawny to 29.340000 */
	cout << "Calka (n = 200): " << całkowanie(1.0, 3.0, 200, n) << endl; /* Dla tych danych wynik poprawny to 29.333400 */
}