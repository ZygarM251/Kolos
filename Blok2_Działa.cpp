#include <iostream>
#include <cmath>
#include <iostream>

using namespace std;
#define Blok4

#ifdef Blok3 

/*
   Rolą funkcji jest odwrócić kolejność cyfr w podanej licznie naturalnej, która nie jest wielokrotnością
   liczby 10.
*/

int reverseInt(int x, int* dlugosc, int* error)
{
    int reversedInt = 0;
    int pop;
    bool firstLoop = true;
    int licznik = 0;
    if (x < 0)
    {
        *error = 1;
    }
    else
    {
        *error = 0;
    }

    /* Zadany argument będziemy przetwarzać tak długo,
        aż wyciągniemy z niego wszystkie cyfry */
    while (x != 0) //zbędny nawias i srednik 
    {
        /* Pobierz cyfrę jedności z zadanej liczby */
        pop = x % 10;
        /* Zakładamy, że nie powinno się odwracać liczb z zerem na koncu,
           bo następuje utrata informacji */
        if (firstLoop == true && pop == 0)// zbedny srednik oraz and zmiast && 
        {
            *error = 1;
        }
        firstLoop = false; //brak srednika 

        /* Skracamy "x" o jedną cyfrę i zapisujemy wynik w "x" */
        x /= 10; // = zmiast /= 
        /* To co zostało obliczone do tej pory przesuwamy na jedno miejsce w prawo
            następnie dodajemy ostatnio zapamiętaną liczbę */
        reversedInt = reversedInt * 10 + pop; //literowka 
        licznik++;

    }

    *dlugosc = licznik;
    return reversedInt;
}
/* 3) Funkjca powinna zwracać dodatkową informację o liczbie znalezionych cyfr wejsciowej oraz zgłaszać
      do kontekstu zewnętrznego poprawność jej wykonania. Funkcja powinna zgłaszać błąd jesli
      wejściowa liczba jest ujemna, lub gdy 0 pojawia się jako ostatnia jej cyfra, np:
      1234506 -> OK, ale już 123450 -> Błąd!
      Dostosuj kod w main do zmian. */

int main() {
    int dlugosc = 0;
    int error = 0;
    int int1, int2, int3, int4 = 0;

    int1 = reverseInt(4, &dlugosc, &error);
    if (error == 0)
    {
        cout << "Odwrotnoscia 4 jest " << int1 << ", o dlugosci: " << dlugosc << " cyfr/y" << endl;//uzycie >> zmiast << przy cout 
    }
    else if (error == 1)
    {
        cout << "Bledna liczba" << endl;
    }
    int2 = reverseInt(1230, &dlugosc, &error);
    if (error == 0)
    {
        cout << "Odwrotnoscia 1230 jest " << int2 << ", o dlugosci: " << dlugosc << " cyfr/y" << endl;
    }
    else if (error == 1)
    {
        cout << "Bledna liczba" << endl;
    }
    int3 = reverseInt(208478933, &dlugosc, &error);
    if (error == 0)
    {
        cout << "Odwrotnoscia 208478933 jest " << int3 << ", o dlugosci: " << dlugosc << " cyfr/y" << endl;
    }
    else if (error == 1)
    {
        cout << "Bledna liczba" << endl;
    }
    int4 = reverseInt(-73634, &dlugosc, &error);
    if (error == 0)
    {
        cout << "Odwrotnoscia -73634 jest " << int4 << ", o dlugosci: " << dlugosc << " cyfr/y" << endl;
    }
    else if (error == 1)
    {
        cout << "Bledna liczba" << endl;
    }
    return 0;
}

#endif 


#ifdef Blok4

struct Wejscie
{
	double xp;
	double xk;
	int n;
	double x;
	double eps;
	double error;
	double sqrtx;
	double popsqrtx;
};

void wpiszWejscie(Wejscie& wejscia, double xp, double xk, int n, double x, double eps, double error, double sqrtx, double popsqrtx)
{
	wejscia.xp = xp;
	wejscia.xk = xk;
	wejscia.n = n;
	wejscia.x = x;
	wejscia.eps = eps;
	wejscia.error = error;
	wejscia.sqrtx = sqrtx;
	wejscia.popsqrtx = popsqrtx;
}

struct Wyjscie
{
	double Szacowanie;
	double wynik;
};

void wpiszWyjscie(Wyjscie& wyjscia, double wynik, double Szacowanie)
{
	wyjscia.wynik = wynik;
	wyjscia.Szacowanie = Szacowanie;
}

/* Całkowana funkcja: */
double funkcjaMatematyczna(double x)
{
	return 2 * sin(x) + cos(x);
}

/* Uwaga oszacowanie całki może wyjść ujemne, gdyż pole funkjci pod osią OX jest odejmowane od pola ponad nią */

double całkowanie(Wejscie& wejscia, Wyjscie& wyjscia)   //double xp, double xk, int n, double error, double eps, double sqrtx, double popsqrtx, double x
{
	//double Oszacowanie;
	if (wejscia.xk < wejscia.xp or wejscia.n <= 2)
	{
		cout << "Błędne dane! ";
		return 0;
	}
	else
	{
		double h = (abs(wejscia.xp) + abs(wejscia.xk)) / wejscia.n;
		wyjscia.Szacowanie = 0;

		//do                                         // while (error >= eps)
		//{
		for (int i = 1; i < wejscia.n; i++)
		{
			while (wejscia.error >= wejscia.eps)
			{
				double a = wejscia.xp + i * h;
				double b = wejscia.xp + (i + 1) * h;
				double Pole_trap = 0.5 * h * (a + b);
				wyjscia.Szacowanie = wyjscia.Szacowanie + Pole_trap;
				wejscia.sqrtx = 0.5 * (wejscia.sqrtx + (wejscia.x / wejscia.sqrtx));
				wejscia.error = fabs(wejscia.popsqrtx - wejscia.sqrtx);
				wejscia.popsqrtx = wejscia.sqrtx;

				cerr << i++ << ": " << wejscia.sqrtx
					<< " err: " << wejscia.error << endl;
			}
		}
		//} 
		//while (q.error >= q.eps);

		cerr << "Wynik: " << wejscia.sqrtx << endl;
		cerr << "Prawidlowy: " << sqrt(wejscia.x) << endl;
		cerr << "Oszacowanie: " << wyjscia.Szacowanie << endl;

		//g.wynik = funkcjaMatematyczna(g.Oszacowanie);
		return g.wynik = funkcjaMatematyczna(g.Szacowanie);
	}
	/* Sprawdź warunki: xk > xp i n > 2. Jesli choć jeden nie jest spełniony przerwij funkcję wynikiem 0 */

		/* Wyznacz wysokość h trapezow jako odcinek |xp, xk| podzielony przez n */
		/* Ustaw wartość oszacowania całki oznaczonej na 0 */

		/* Powtarzaj n razy: */
			/* Wyznacz podstawy trapezów dla i-tej itreacji jako wartości całkowanej funkcji w punktach:
			   a = xp+i*h i b = xp+(i+1)*h, gdzie i to numer iteracji. */
			   /* Wylicz pole trapezu jako 0.5*h*(a+b) i dodaj je do oszacowania całki */

	   /* Zwroc oszacowanie całki jako wynik funkjci */
	//return Oszacowanie;
}

ostream& operator<<(ostream& str, Wyjscie const& wyjscia)
{
	str << "Oszacowanie całki to: " << wyjscia.wynik;

	return str;
}

int main()
{
	setlocale(LC_ALL, "");
	//double xp = 10, xk = 25;
	//int n = 10000;
	//double eps = 0.005;
	//double x = 10.0;
	//double error = x;
	//double sqrtx = x;
	//double popsqrtx = x;
	Wejscie wej;
	wpiszWejscie(wej, 25.0, 29.0, 10000, 5.0, 0.0005, 5.0, 5.0, 5.0);
	Wyjscie wyj;
	całkowanie(wej, wyj);   //xp, xk, n, error, eps, sqrtx, popsqrtx, x
	if (wej.xk > wej.xp)
	{
		cout << Wyjscie(wyj) << endl;
	}
	else
	{
		return 0;
	}
	//cout << Wyjscie(g) << endl;
}
#endif 

#ifdef Blok5

#include <iostream>
using namespace std;

struct DaneWejsciowe
{
	double xp, xk, n, eps;
};

struct DaneWyjsciowe
{
	double wynikCalki;
};

void pobieranieDanychCalki(DaneWejsciowe& dane)
{
	cout << "Podaj xp , xk , n dla ktorego bedzie dzielona podstawa calki miedzy xp i xk i podaj eps :" << endl;
	cin >> dane.xp >> dane.xk >> dane.n >> dane.eps;
}

void wyswietlanieDanejCalki(DaneWyjsciowe dane)
{
	cout << "Podana calka wynosi:" << dane.wynikCalki << endl;
}

/* Całkowana funkcja: */
double funkcjaMatematyczna(double x)
{
	return 2 * sin(x) + cos(x);
}
/* Uwaga oszacowanie całki może wyjść ujemne, gdyż pole funkjci pod osią OX jest odejmowane od pola ponad nią */

DaneWyjsciowe całkowanie(DaneWejsciowe dane)
{
	DaneWyjsciowe wynik = { 0.0 };
	/* Sprawdź warunki: xk > xp i n > 2. Jesli choć jeden nie jest spełniony przerwij funkcję wynikiem 0 */
	if (dane.xk < dane.xp || dane.n < 2)
	{
		return wynik;
	}
	double wysokoscH = (dane.xp - dane.xk) / (double)dane.n;
	double wartoscOszacowaniaCalkiOznaczonej = 0.0;
	/* Wyznacz wysokość h trapezow jako odcinek |xp, xk| podzielony przez n */
	/* Ustaw wartość oszacowania całki oznaczonej na 0 */
	double tempWartosciOszacowanejCalkiNieoznaczonej = 0.0;
	int i = 0;
	do
	{
		double a = funkcjaMatematyczna(dane.xp + i * wysokoscH), b = funkcjaMatematyczna(dane.xp + (i + 1.0) * wysokoscH); i++;
		double poleTrapezu = 0.5 * wysokoscH * (a + b);
		tempWartosciOszacowanejCalkiNieoznaczonej = wartoscOszacowaniaCalkiOznaczonej;
		wartoscOszacowaniaCalkiOznaczonej += poleTrapezu;
	} while (tempWartosciOszacowanejCalkiNieoznaczonej - wartoscOszacowaniaCalkiOznaczonej < dane.eps);
	wynik.wynikCalki = wartoscOszacowaniaCalkiOznaczonej;
	/* Powtarzaj n razy: */
			/* Wyznacz podstawy trapezów dla i-tej itreacji jako wartości całkowanej funkcji w punktach:
			   a = xp+i*h i b = xp+(i+1)*h, gdzie i to numer iteracji. */
			   /* Wylicz pole trapezu jako 0.5*h*(a+b) i dodaj je do oszacowania całki */

	   /* Zwroc oszacowanie całki jako wynik funkjci */
	return wynik;
}

int main()
{
	DaneWejsciowe  daneWejsciowe;
	pobieranieDanychCalki(daneWejsciowe);
	DaneWyjsciowe daneWyjsciowe = całkowanie(daneWejsciowe);
	wyswietlanieDanejCalki(daneWyjsciowe);
	return 0;
}

#endif