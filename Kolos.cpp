#include <stdlib.h>
#include <stdio.h>

using namespace std;

struct tablica_alokacji {
    char liczba_zmian_adresu;
    char tablica[3];
    double* dane;
};

void inkrementuj_liczbe_zmian_adresu(tablica_alokacji* tablica) {
    tablica->liczba_zmian_adresu++;
}

tablica_alokacji* tworzenie_alokacji_tablicy(tablica_alokacji* tablica, int size) {
    if (tablica == NULL) {
        tablica = (tablica_alokacji*)malloc(sizeof(tablica_alokacji));
        tablica->liczba_zmian_adresu = 0;
        tablica->tablica[0] = 0;
    }

    inkrementuj_liczbe_zmian_adresu(tablica);
    tablica->tablica[1] = (size >> 8) & 0xFF;
    tablica->tablica[2] = size & 0xFF;

    tablica->dane = (double*)realloc(tablica->dane, size * sizeof(double));

    return tablica;
}

void dealokacja_tablicy(tablica_alokacji* arr) {
    free(arr->dane);
    free(arr);
}

double* wczytaj_liczby(char* sciezka, int* rozmiar) {
    FILE* plik = fopen(sciezka, "r");
    if (plik == NULL) {
        printf("Nie mozna otworzyc pliku %s\n", sciezka);
        return NULL;
    }

    int ile_liczb = 0;
    double liczba;
    while (fscanf(plik, "%lf,", &liczba) != EOF) {
        ile_liczb++;
    }
    rewind(plik);

    double* liczby = (double*)malloc(ile_liczb * sizeof(double));
    int i = 0;
    while (fscanf(plik, "%lf,", &liczba) != EOF) {
        liczby[i] = liczba;
        i++;
    }

    *rozmiar = ile_liczb;
    return liczby;
}

int main() {
    tablica_alokacji* alokacja_tablicy = NULL;
    int rozmiar = 0;
    double* dane = wczytaj_liczby("dane.txt", &rozmiar);
    alokacja_tablicy = tworzenie_alokacji_tablicy(alokacja_tablicy, rozmiar);

    for (int i = 0; i < rozmiar; i++) {
        alokacja_tablicy->dane[i] = dane[i];
    }

    dealokacja_tablicy(alokacja_tablicy);
    free(dane);

    return 0;
}