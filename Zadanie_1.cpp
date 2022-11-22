#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	int n, licznik = 0, wypisanie = 0, liczby = 1, ilosc_liczb = 0, suma = 0, iloczyn = 1, s = 0, g = 0;
	do {
		cout << "Podaj liczby";
		cin >> n;
		wypisanie += n * liczby;
		if (n % 2 != 0 && n>=1 && n<=9)
		{
			licznik++;
		}
		else
		{
			licznik = 0;
		}
		ilosc_liczb++;
		suma += n;
		iloczyn *= n;
		liczby = liczby * 10;

	} while (licznik != 2);
	cout << wypisanie << endl;
	cout << suma << endl;
	cout << iloczyn << endl;

	s = suma / ilosc_liczb;
	g = pow(iloczyn, 1.0 / ilosc_liczb);
	cout << "Średnia arytmetyczna wynosi: " << s << endl;
	cout << "Średnia geometryczna wynosi: " << g << endl;

	double y = 0;
	const int pi = 3.1415,e=2.7182;
	y = pow(g, pi) * log(e)*(s - 1 / s + 2);
	cout << scientific << setprecision(2) << "Funkcja wynosi: " << y;


}
