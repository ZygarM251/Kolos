#include <iostream>
#include <exception> 
#include <exception> 
#include "Inicjacja_funkcji.h"

using namespace std;


namespace Testy {

	void test_szukaj_pierwszy_znak() {
		struct Osoba {
			string imie;
			int wiek;
		};

		Osoba tablica[4] = {
			{"Anna", 23},
			{"Jan", 30},
			{"Piotr", 28},
			{"Anna", 20}
		};

		int rozmiar = sizeof(tablica) / sizeof(tablica[0]);

		
		try {
			szukaj_pierwszy_znak(tablica, rozmiar, new Osoba{ "Kasia", 25 });
			throw(false);
		}
		catch (const exception& e) {
			throw(string(e.what()) == "Nie ma takiego elementu");
		}

		throw(szukaj_pierwszy_znak(tablica, rozmiar, new Osoba{ "Jan", 30 }) == 1);

		throw(szukaj_pierwszy_znak(tablica, rozmiar, new Osoba{ "Anna", 23 }) == 0);

		throw(szukaj_pierwszy_znak(tablica, rozmiar, new Osoba{ "Anna", 20 }) == 3);
	}

}


int main()
{
	Testy::test_szukaj_pierwszy_znak();
	return 0;
}
