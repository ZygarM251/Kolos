#include <iostream>//dodanie biblioteki iostream

using namespace std;
/* Funkcja dla zadania z bloku 3 - termin 0 (wt):
 *  Jej zadaniem jest wyznaczyć odległość w zbiorze liczb całkowitych - liczbę iteracji jaką należy wykonać,
 *  aby z pierwszego wystąpienia dojść do ostatniego.
 *  Funkcja powinna przyjmować tablicę liczb całkowitych i zwrcać dległość - liczba całkowita).
 *  Jeśli liczba wystapi tylko raz, prawidłowym wynikiem jest 0. Jesli jedyne dwa wystąpienia sąsiadują ze sobą to 1.
 *  w innych przypadkach powinna to być liczba naturalna np.: dla zbioru:
 *  1 2 3 4 5 6 7 8 1 2 3 4 5 i szukanej 1, odległość to 8.
 */

int odleglosc(int dane[], const int ROZMIAR, char& szukana)// zmiana typu funkcji na liczbe całkowitą, zmiana typu parametru dane na tablicę liczb całkowitych, 
//zmiana typu parametru rozmiaru tablicy na liczbę całkowitą , zmiana wskaźnika parametru na alias parametru
{
    /* Deklaracja zmiennych pomocniczych: */
    int pierwsze = 0, ostatnie = 0,liczba_wystapien=0;
    bool znalezionoPierwsze = true;//przypisanie wartości true do zmiennej bool

    /* W pętli szukamy jednoczesnie pierwszego i ostatniego wystąpienia: */
    for (int i = 0; i < ROZMIAR; i++)//Zmiana warunku pętli z >= na <
    {
        if (dane[i] == szukana)
        {
            liczba_wystapien++;
            if (znalezionoPierwsze)
            {
                pierwsze = i; //do zmiennej pierwsze zamiast *szukana przypisuje indeks dla którego wystąpiła pierszszy raz szukana wartość
                znalezionoPierwsze = false;
            }
            if (!znalezionoPierwsze)
            {
                ostatnie =  i;//do zmiennej ostatnie przypisuje wartość pozycji na którym została znaleziona ostatnia liczba szukana
            }
        }
    }

    if (dane == nullptr || ROZMIAR < 0)
    {
        cout << "Błąd";
        return 0;
    }

    cout <<"Liczba wystapien liczby szukanej: " << liczba_wystapien << endl;
    /* Zwracamy odległość: */
    return ostatnie - pierwsze;//usuwam niepotrzebnego odejmowania -1  ze zwracanego wyniku funkcji
}

/* Polecnie 3: rozbuduj kod i interfejs funkcji tak, aby w funkcji main można było odebrać, nie
 * tylko odległosć, ale także liczbę wszystkich wystąpień szukanej liczby w zbiorze danych. Funkcja
 * powinna sygnalizaować błąd jesli:
 *  - podamy rozmiar mniejszy o 1,
 *  - nie znajdzie żadnego wystąpeinia liczby
 *  - wskazana tablica to nullptr.
 */

 /* Użyj poprawionej funkcji w main zgodnie z jej przeznaczeniem. Samodzielnie przygotuj
  * dane do pokazania jej działania. Program powienien tak wyświetalć dane, aby dało się
  * łatwo sprawdzic poprawność działania funkjci.
  */

int main() 
{
    const int ROZMIAR=14;
    char szukana=1;
    int dane[ROZMIAR] = { 1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4 ,5,1 };

    cout<<"odleglosc od tych samych szukanych: " << odleglosc(dane, ROZMIAR, szukana);
    
}
