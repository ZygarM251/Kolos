#include <cstdint>
#include <iostream>

using namespace std;

struct struktura
{
    int    calkowita;
    double rzeczywista;
};

int szukaj(struktura *tablica, const int rozmiar, struktura szukana)
{
    for (int i = 0; i < rozmiar; i++)
    {
        if (tablica->calkowita == szukana.calkowita &&
            tablica->rzeczywista == szukana.rzeczywista)
        {
            return i;
        }
    }
    throw std::runtime_error("Elementu nie znaleziono");
}

int szukaj(struktura *tablica, const int rozmiar, struktura szukana)
{
    int ostatni_indeks = -1;
    for (int i = 0; i < rozmiar; i++)
    {
        if (tablica->calkowita == szukana.calkowita &&
            tablica->rzeczywista == szukana.rzeczywista)
        {
            ostatni_indeks = i;
        }
    }
    if (ostatni_indeks == -1)
        throw std::runtime_error("Elementu nie znaleziono");
}

namespace Testy
{

bool Test1()
{
    try
    {
        struktura *tablica = new struktura[10];
        for (int i = 0; i < 10; i++)
        {
            tablica[i].calkowita   = i;
            tablica[i].rzeczywista = double(i) / 3;
        }
        struktura szukana;
        szukana.calkowita   = 11;
        szukana.rzeczywista = 0.1;
        szukaj(tablica, 10, szukana);
        return false;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return true;
    }
}
bool Test2()
{
    try
    {
        struktura *tablica = new struktura[10];
        for (int i = 0; i < 10; i++)
        {
            tablica[i].calkowita   = i;
            tablica[i].rzeczywista = double(i) / 3.0;
        }
        struktura szukana;
        szukana.calkowita   = 1;
        szukana.rzeczywista = 1.0 / 3.0;
        szukaj(tablica, 10, szukana);
        return true;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return false;
    }
}
bool Test3()
{
    try
    {
        struktura *tablica = new struktura[10];
        for (int i = 0; i < 10; i++)
        {
            tablica[i].calkowita   = i;
            tablica[i].rzeczywista = double(i) / 3;
        }
        tablica[3].calkowita   = 0;
        tablica[3].rzeczywista = 0.0;
        struktura szukana;
        szukana.calkowita   = 0;
        szukana.rzeczywista = 0.0;
        szukaj(tablica, 10, szukana);
        return true;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return false;
    }
}

}; // namespace Testy

struct tablica_dynamiczna
{
    double  *tablica = nullptr;
    uint32_t rozmiar = 0;
};

void alokuj(
    tablica_dynamiczna *tab,
    const uint32_t
        rozmiar) // w teorii uint32_t to będzie najprawdopodobniej unsigned int,
                 // ale standard nie określa konkretnie ile bitów ma mieć int
{
    delete[] tab->tablica;
    tab->tablica = new double[rozmiar];

    uint32_t zmiany =
        tab->rozmiar & 255; // 255 bo to 8 bitów w stanie "1", z operatorem "&"
                            // zwracają AND, w tym przypadku kopiują wszystkie
                            // jedynki z pierwszych ośmiu bitów rozmiaru;
    tab->rozmiar  = (rozmiar << 24);
    tab->rozmiar += ++zmiany;
}

void dealokuj(tablica_dynamiczna *tab)
{
    tab->rozmiar =
        tab->rozmiar & 255; // 255 bo to 8 bitów w stanie "1", z operatorem "&"
                            // zwracają AND, w tym przypadku kopiują wszystkie
                            // jedynki z pierwszych ośmiu bitów rozmiaru;
    delete[] tab->tablica;
}

void czytajZPliku(tablica_dynamiczna *tab, const char *nazwa_pliku)
{
    /*nie pamiętam jak sie to robilo z tymi FILE, ale powinieneś to zrobić na
     * zasadzie przejechania przez plik i zliczenia danych, przewinięcia głowicy
     * na start, alokacji tablicy a następnie jeszcze raz przejdź przez plik i
     * wczytaj dane do tablicy*/
}

int main() {}