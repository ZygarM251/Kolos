#include "Inicjacja_funkcji.h"
#include <exception> 
using namespace std;

template<typename Testy>
int szukaj_pierwszy_znak(Testy* tablica, int rozmiar, Testy* szukana) {
    for (int i = 0; i < rozmiar; i++) {
        if (*tablica == *szukana) {
            return i;
        }
        tablica++;
    }
    throw exception("Nie ma takiego elementu");
}

template<typename Testy>
int szukaj_ostatni_znak(Testy* tablica, int rozmiar, Testy* szukana) {
    int indeks = -1;
    for (int i = 0; i < rozmiar; i++) {
        if (*tablica == *szukana) {
            indeks = i;
        }
        tablica++;
    }
    if (indeks == -1) {
        throw exception("Nie ma takiego elementu");
    }
    return indeks;
}