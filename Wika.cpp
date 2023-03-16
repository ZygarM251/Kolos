// Wika.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <ctime>
using namespace std;
//Zmieniając ostatnią literę w poniższej instrukcji na A, B, lub C wybierasz aktywne zadanie.
#define ZadanieB 

#ifdef ZadanieA

double dlOdcinka(double x1, double y1, double x2, double y2)
{
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

double sumaKatow(double* obX, double* obY, int liczPkt, double x, double y)
{
	double a, b, c, kat, suma = 0;
	for (int i = 0; i < liczPkt; i++)
	{
		int j = (i + 1) % liczPkt;
		c = dlOdcinka(obX[i], obY[i], obX[j], obY[j]);
		a = dlOdcinka(x, y, obX[i], obY[i]);
		b = dlOdcinka(x, y, obX[j], obY[j]);
		kat = acos(0.5 * (a / b + b / a - c * c / (a * b)));
		suma += kat;
	}
	return suma;
}

bool czyPunktNalezyDoObszaru(double* obX, double* obY, int liczPkt, double x, double y)
{
	if (obX == nullptr || obY == nullptr) throw std::invalid_argument("Nullptr!");
	if (liczPkt <= 2) throw std::domain_error("LiczPkt<=2");
	const double DWA_PI = 2.0 * 3.1415926;
	const double EPS = 0.00001;
	double modRoznicy = abs(sumaKatow(obX, obY, liczPkt, x, y) - DWA_PI);
	return (-EPS < modRoznicy&& modRoznicy < EPS);
}
void test1()
{

	setlocale(LC_ALL, "");
	double tabX[] = { 0.0,-1.0, 1.0, 3.0 };
	double tabY[] = { 0.0, 1.0, 2.0, 1.0 };
	double xP = -0.5;
	double yP = 0.5;
	const int SIZE = sizeof(tabX) / sizeof(double);
	cout << "Test numer 1: czy funkcja klasyfikuje poprawnie punkt położony wewnątrz wielokąta? - ";
	if (czyPunktNalezyDoObszaru(tabX, tabY, SIZE, xP, yP))
	{
		cout << "true!" << endl;
	}
	else
	{
		cout << "false!" << endl;
	}
}
void test2()
{

	setlocale(LC_ALL, "");
	double tabX[] = { 0.0,-1.0, 1.0, 3.0 };
	double tabY[] = { 0.0, 1.0, 2.0, 1.0 };
	double xP = -0.5;
	double yP = 0.5;
	const int SIZE = sizeof(tabX) / sizeof(double);
	cout << "Test numer 2: czy funkcja klasyfikuje poprawnie punkt położony na zewnątrz wielokąta? - ";
	if (czyPunktNalezyDoObszaru(tabX, tabY, SIZE, xP, yP))
	{
		cout << "false!" << endl;
	}
	else
	{
		cout << "true!" << endl;
	}
}
void test3()
{

	setlocale(LC_ALL, "");
	double tabX[] = { 0.0,-1.0, 1.0, 3.0 };
	double tabY[] = { 0.0, 1.0, 2.0, 1.0 };
	double xP = -0.5;
	double yP = 0.5;
	const int SIZE = sizeof(tabX) / sizeof(double);
	cout << "Test numer 3: false gdy któryś ze wskaźników przyjmuje nullptr - ";
	try
	{
		czyPunktNalezyDoObszaru(nullptr, tabY, SIZE, xP, yP);
	}
	catch (invalid_argument)
	{
		cerr << "FAIL - przez nullptr!" << endl;
		return;
	}
	catch (...) {}
	cerr << "SUCCESS!" << endl;
}
void test4()
{

	setlocale(LC_ALL, "");
	double tabX[] = { 0.0,-1.0 };
	double tabY[] = { 0.0, 1.0 };
	double xP = -0.5;
	double yP = 0.5;
	const int SIZE = sizeof(tabX) / sizeof(double);
	cout << "Test numer 4: false gdy liczba wierzchołków wielokąta będzie mniejsza od 3. - ";
	try
	{
		czyPunktNalezyDoObszaru(tabX, tabY, SIZE, xP, yP);
	}
	catch (domain_error)
	{
		cerr << "FAIL - liczba wierzchołków < 2 lub liczba wierzchołków = 2!" << endl;
		return;
	}
	catch (...) {}
	cerr << "SUCCESS!" << endl;
}
void main(void)
{
	setlocale(LC_ALL, "");
	double tabX[] = { 0.0,-1.0, 1.0, 3.0 };
	double tabY[] = { 0.0, 1.0, 2.0, 1.0 };
	double xP = -0.5;
	double yP = 0.5;
	const int SIZE = sizeof(tabX) / sizeof(double);
	cout << czyPunktNalezyDoObszaru(tabX, tabY, SIZE, xP, yP) << endl;
	test1();
	test2();
	test3();
	test4();
}
#endif

#ifdef ZadanieB

int wyszukajPierwsza(double* tablica, int rozmiar, double wartSzukana)
{
	// Sparwdzenie poprawności danych wejściowych:
	if (tablica == nullptr) throw std::invalid_argument("tablica = nullptr");
	if (rozmiar < 1) throw std::length_error("rozmiar < 1");

	for (int index = 0; index < rozmiar; index++)
	{
		if (tablica[index] == wartSzukana)
			return index;  // Znaleziono pierwsze wystąpienie - przerywam
	}
	throw std::domain_error("Wartosc nie wystąpiła");
}

int ileRazyZnak(const char* text, char znak)
{
	int liczbaWystapien = 0;
	while (*text)
	{
		if (*text == znak) liczbaWystapien++;
		{
			text++;
		}
	}
	return liczbaWystapien;

}
void t1pierwsza()
{
	setlocale(LC_ALL, "");
	double tablica[] = { 1,2,3,4,5,6,7,8,9 };
	const int rozmiar = sizeof(tablica) / sizeof(double);
	double wartSzukana = 2;
	cout << "Test pierwszy: czy funkcja prawidłowo znajduje wartości, która występują w tablicy - ";
	if (wyszukajPierwsza(tablica, rozmiar, wartSzukana) == 1)
	{
		cout << "true!" << endl;
	}
	else
	{
		cout << "false!" << endl;
	}
}
void t2pierwsza()
{
	setlocale(LC_ALL, "");
	double tablica[] = { 1,2,3,2,4,5,6,7,8,9 };
	const int rozmiar = sizeof(tablica) / sizeof(double);
	double wartSzukana = 2;
	cout << "Test drugi: czy funkcja prawidłowo zwróci pozycję pierwszego wystąpienia wartości, która występuje w tablicy > 1 raz - ";
	if (wyszukajPierwsza(tablica, rozmiar, wartSzukana) == 1)
	{
		cout << "true!" << endl;
	}
	else
	{
		cout << "false!" << endl;
	}
}
void t3pierwsza()
{
	setlocale(LC_ALL, "");
	double tablica[] = { 1,2,3,4,5,6,2,7,8,9 };
	const int rozmiar = sizeof(tablica) / sizeof(double);
	double wartSzukana = 2;
	bool czyzwraca = false;
	cout << "Test trzeci: czy funkcja prawidłowo sygnalizuje błąd adresu tablicy (nullptr) - ";
	try
	{
		wyszukajPierwsza(nullptr, rozmiar, wartSzukana);
	}
	catch (invalid_argument)
	{
		czyzwraca = true;
	}
	if (czyzwraca)
	{
		cerr << "SUCCESS!" << endl;
	}
	else
	{
		cerr << "FAIL!" << endl;
	}

}
void t4pierwsza()
{
	setlocale(LC_ALL, "");
	double tablica[] = { 1,2,3,4,5,6,7,8,9 };
	const int rozmiar = -1;
	double wartSzukana = 2;
	bool czyzwraca = false;
	cout << "Test czwarty: czy funkcja prawidłowo sygnalizuje błąd zerowego lub ujemnego rozmiaru - ";
	try
	{
		wyszukajPierwsza(tablica, rozmiar, wartSzukana);
	}
	catch (length_error)
	{
		czyzwraca = true;
	}
	if (czyzwraca)
	{
		cerr << "SUCCESS!" << endl;
	}
	else
	{
		cerr << "FAIL!" << endl;
	}
}
void t5pierwsza()
{
	setlocale(LC_ALL, "");
	double tablica[] = { 1,2,3,4,5,6,7,8,9 };
	const int rozmiar = sizeof(tablica) / sizeof(double);
	double wartSzukana = 2;
	bool czyzwraca = false;
	cout << "Test piąty: czy funkcja prawidłowo sygnalizuje nieznalezienie wartości, której nie było w tablicy - ";
	try
	{
		wyszukajPierwsza(tablica, rozmiar, wartSzukana);
	}
	catch (domain_error)
	{
		czyzwraca = true;
	}
	if (czyzwraca)
	{
		cerr << "FAIL!" << endl;
	}
	else
	{
		cerr << "SUCCESS!" << endl;
	}
}
void t1znak()
{
	setlocale(LC_ALL, "");
	char tekst[] = "ekst do testów";
	char znak = 't';
	cout << "Test pierwszy: czy funkcja policzy wskazany znak znajdujący się w tekście - ";
	if (ileRazyZnak(tekst, znak) == 3)
	{
		cout << "true!" << endl;
	}
	else
	{
		cout << "false!" << endl;
	}

}
void t2znak()
{
	setlocale(LC_ALL, "");
	char tekst[] = "tekst do testów";
	char znak = 't';
	cout << "Test drugi: czy funkcja zaliczy znak zajdujacy się na początku tekstu - ";
	if (ileRazyZnak(tekst, znak) == 4)
	{
		cout << "true!" << endl;
	}
	else
	{
		cout << "false!" << endl;
	}

}
void t3znak()
{
	setlocale(LC_ALL, "");
	char tekst[] = "tekst do testów";
	char znak = 'a';
	cout << "Test trzeci: czy funkcja zwróci 0 jeśli podanego znaku nie ma w tekście - ";
	if (ileRazyZnak(tekst, znak) == 0)
	{
		cout << "true!" << endl;
	}
	else
	{
		cout << "false!" << endl;
	}
}
int main()
{
	srand(time(NULL));
	double tablica[] = { 1,2,3,4,5,6,7,8,9 };
	const int rozmiar = sizeof(tablica) / sizeof(double);
	double wartSzukana = 2;
	cout << wyszukajPierwsza(tablica, rozmiar, wartSzukana) << endl;
	char tekst[] = "tekst do testów";
	char znak = 't';
	cout << ileRazyZnak(tekst, znak) << endl;

	for (int i = 0; i < 8; i++)
	{
		int liczba = ((rand() % 😎 + 1);
		cout << "test" << liczba << endl;
		switch (liczba)
		{
		case 1:
			t1pierwsza();
			break;
		case 2:
			t2pierwsza();
			break;
		case 3:
			t3pierwsza();
			break;
		case 4:
			t4pierwsza();
			break;
		case 5:
			t5pierwsza();
			break;
		case 6:
			t1znak();
			break;
		case 7:
			t2znak();
			break;
		case 8:
			t3znak();
			break;
		}
	}
}

#endif

#ifdef ZadanieC
int main()
{
	// TU ROZWIĄZUJ ZADANIE C:
}
#endif