#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

#define Blok2

#ifdef Blok1
int main()
{
	double  liczba_naturalna;
	int n = 0;

	do 
	{
		cout << "Podaj liczbe n: ";
		cin >> liczba_naturalna;
		n = (int)liczba_naturalna;
	} while (n % 2 != 0 || n < 6|| liczba_naturalna / n > 1.0);

	double liczba = 0.0,s = 0.0,g = 1.0;
	int ilosc_liczb=0,liczba_z_przdzialu=0;

	while (n != ilosc_liczb && liczba_z_przdzialu < 4)
	{
		ilosc_liczb++;
		cout << "Podaj liczbe: ";
		cout << endl;
		cin >> liczba;
		if (0.1 <= liczba || liczba <= 9.9)
		{
			liczba_z_przdzialu++;
		}
		cout << "liczba nr:" << liczba_z_przdzialu << endl;
		if (liczba > 0)
		{
			s += liczba;
			g *= liczba;
		}
		
		cout << "suma: " << s << endl;
		cout << "iloczyn: " << g << endl;
	}
	const double pi = 3.14;
	double y = pow(s, (1.0 / pi)) * log(n) * ((g + 1) / (g - 1));
	cout << scientific << setprecision(8) << "wynik funkcji y wynosi:"  << y;
}

#endif

#ifdef Blok2
int main()
{
	srand(time(0));

	constexpr int x = 4, y = 7;
	int tablica[x][y];
	int nr_kolumny;

	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++)
		{
			tablica[i][j] = (rand()%15)-5;
		}

		
	for (int i = 0; i < x; i++)
	{
		cout << endl;
		for (int j = 0; j < y; j++)
		{
			cout <<setw(3)<< tablica[i][j];
		}
	}
	cout << endl;
	do 
	{
		cout << "Podaj numer kolumny od 0 do 6: " << endl;
		cin >> nr_kolumny;
	} while (nr_kolumny>=6 && nr_kolumny<=0);


	int *wsk_kolumny = &tablica[0][0];
	int max_wartosc = 0,nr_wiersza=0;

	wsk_kolumny += nr_kolumny;
	max_wartosc = *wsk_kolumny;

	for (int i = 1; i < x; i++)
	{
		wsk_kolumny += 7;
		if (max_wartosc<=*wsk_kolumny)
		{
			max_wartosc = *wsk_kolumny;
			nr_wiersza = i;
		}
	}
	cout << "numer_klolumny[" << nr_kolumny << "]" << endl
		<< "numer_wiersza[" << nr_wiersza << "]" << endl;

	cout << max_wartosc;
	

	for (int i = 0; i < x; i++)
	{
		cout << endl;
		for (int j = 0; j < y; j++)
		{
			if (i==nr_wiersza&&j==nr_kolumny)
			{
				cout << setw(3) << "X";
			}
			else
			{
				cout << setw(3) << tablica[i][j];
			}
			if (j!=6)
			{
				cout << " :";
			}
		}
	}

}
#endif