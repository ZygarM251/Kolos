#include <iostream>             // dodanie biblioteki iostream oraz cmath
#include <cmath>

using namespace std;

/* Funkcje dla zadania z bloku 4 - Termin 0:
*  Jej zadaniem jest wyznaczyć położenie miejsca zerowego funkcji w zadanym zakresie.
*  Algorytm działa w założeniu, że we wskazanym zakresie funkcja ma tylko jedno
*  miejsce zerowe. Na granicach zakresu funkjca powinna przyjmować wartości
*  o przeciwnych znakach. Kolejne kroki podane są w ciele funkcji.
*/


struct wejscie
{
    double xp;
    double xk;
    double a;
    double b;
    double c;
    double d;
    int n;
    double eps;
};


struct wyjscie
{
    double roznica;
    double fx0;
    bool powodzenie;
};


double funkcja(double a, double b, double c, double d, double x)//usuniecie zbędnego przecinka
/* a i b to parametry funkcji liniowej, x to jej argument */
{
    return a * x * x * x + b * x * x + c * x + d;
}

void podaj_dane(wejscie& wej, double xp, double xk, double a, double b, double c, double d, int n, double eps)
{
    wej.xp = xp;
    wej.xk = xk;
    wej.a = a;
    wej.b = b;
    wej.c = c;
    wej.d = d;
    wej.n = n;
    wej.eps = eps;
}

double miejsceZerowe(wejscie& wej, wyjscie& wyj)
{
    /*UWAGA:  f(x) uzyskujemy przez wywołanie: funkcja(a,b,c,d,x) */
    /* 0. sprawdź czy xk > xp i f(xk) ma różny znak od f(xp) jesli
     * którykolwiek z tych warunków nie jest spełniony - zakończ funkcję
     * z sygnalizacją błędu (arg. powodzenie równy false).
     */
    double funkcja_xp, funkcja_xk;

    funkcja_xp = funkcja(wej.a, wej.b, wej.c, wej.d, wej.xp);
    funkcja_xk = funkcja(wej.a, wej.b, wej.c, wej.d, wej.xk);


    if (funkcja_xk*funkcja_xp>0 || wej.xk> wej.xp)
    {
        wyj.powodzenie = false;
        return 0;
    }
    else
    {
        wyj.powodzenie = true;
    }

     /* Powtarzaj n razy: */
        /* Wyznacz parametry (wsp. kierunkowy i wyraz wolny) funkcji liniowej g(x)
         * przechodzącej przez punkty (xp,f(xp)) i (xk,f(xk)). */
         /* Wylicz miejsce zerowe x0 otrzymanej funkcji liniowej g(x). */
         /* Wylicz f(x0) i */
             /* zastąp xp wartością x0 jeśli f(x0) i f(xp) mają ten sam znak */
             /* w przeciwnym wypadku zastąp xk wartością x0. */
       /* zwróć ostatnie x0 (funkcja musi sygnalizować powodzenie równe true) */

    for (int i = 0; i < wej.n; i++)
    {
        double poprzednia_wartosc_m0;
        double wsp_kierunkowy = (funkcja_xk - funkcja_xp),
            wyraz_wolny = wej.xp;

        double funkcja_liniowa = 0, x = 0;
        funkcja_liniowa = ((funkcja_xk - funkcja_xp) * (x - wej.xp)) / (wej.xk - wej.xp) + wej.xp;

        double miejsce_zerowe_gx = (-wej.xp) / (funkcja_xk - funkcja_xp),
            funkcja_x0 = funkcja(wsp_kierunkowy, wyraz_wolny, wej.c, wej.d, miejsce_zerowe_gx);

        if (funkcja_x0 * funkcja_xp > 0)
        {
            wej.xp = miejsce_zerowe_gx;
        }
        else
        {
            wej.xk = miejsce_zerowe_gx;
        }

        poprzednia_wartosc_m0 = abs(miejsce_zerowe_gx - funkcja_x0);
        if (poprzednia_wartosc_m0<=wej.eps)
        {
            miejsce_zerowe_gx = funkcja_x0;
            return poprzednia_wartosc_m0;
        }

        return miejsce_zerowe_gx;
    }
}

ostream& operator<<(ostream& str, wyjscie& wyj)
{
    if (wyj.powodzenie)
    {
        cout << " f(x0) = " << wyj.fx0 << ", roznica w szacowaniu wyniku f(x0): " << wyj.roznica << endl;
        return str;
    }
    else
    {
        cout << "Bledne dane!\n";
        return str;
    }
}

/* Polecenie 2: Zmodyfikuj kod programu tak, aby agorytm kończył się jeśli różnica pomiędzy
 * dwoma kolejnymi oszacowaniami wyniku (x0) jest mniejsza od zadenego eps.
 * Zmodyfikuj tak interfejs funkcji, aby można było zadać eps, oraz zwrócić wartość f(x0) i różnicę
 * w oszacowaniach (wartość sparwdzaną w nowym kryterium zbieżności).
 */

 /* Polecenie 3: Zmodyfikuj tak interfejs funkcji, aby wszytskie dane wejściowe przekazywać
  * za pomocą struktury, oraz wszystkie wyniki odbierać w postaci struktury. Napisz funkcje
  * do wypełniania struktury wejściwem treścią i do wyświetlania struktury wyjściowej na ekranie.
  */

using namespace std;

int main()
{
    /* main dla zadania z bloku 4*/
    bool czyOK = true;
    double a = 2.0, b = 1.0, c = -2.0, d = 1.0, poczatek = 2.0, koniec = -2.0;
    int liczbaIteracji = 10;
    double eps = 0.0001;
    wejscie  wej = { 0 };
    wyjscie  wyj = { 0 };

    podaj_dane(wej,poczatek, koniec, a, b, c, d, liczbaIteracji,czyOK);
    miejsceZerowe(wej, wyj);

    if (czyOK)
    {
        cout << "Miejsce zerowe funkjci y = " << a << " x + " << b << " w : " << wyj << endl;
    }
    else
    {
        cout << "Bledne dane!\n";
    }
}