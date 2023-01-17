#include <iostream> //brak bibloteki iosteam

/* Funkcje dla zadania z bloku 4 - Termin 0:
*  Jej zadaniem jest wyznaczyæ po³o¿enie miejsca zerowego funkcji w zadanym zakresie.
*  Algorytm dzia³a w za³o¿eniu, ¿e we wskazanym zakresie funkcja ma tylko jedno
*  miejsce zerowe. Na granicach zakresu funkjca powinna przyjmowaæ wartoœci
*  o przeciwnych znakach. Kolejne kroki podane s¹ w ciele funkcji.
*/
using namespace std; //namespace w z³ym miejscu

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


double funkcja(double a, double b, double c, double d, double x) //zbêdny przecinek
{
    return a * x * x * x + b * x * x + c * x + d;
}


void podaj(wejscie& wej, double xp, double xk, double a, double b, double c, double d, int n, double eps)
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


void miejsceZerowe(wejscie& wej, wyjscie& wyj)
{
    wyj.powodzenie = true;
    if (wej.xk <= wej.xp)
    {
        wyj.powodzenie = false;
        return;
    }
    if (funkcja(wej.a, wej.b, wej.c, wej.d, wej.xp) > 0 && funkcja(wej.a, wej.b, wej.c, wej.d, wej.xk) > 0)
    {
        wyj.powodzenie = false;
        return;
    }
    if (funkcja(wej.a, wej.b, wej.c, wej.d, wej.xp) < 0 && funkcja(wej.a, wej.b, wej.c, wej.d, wej.xk) < 0)
    {
        wyj.powodzenie = false;
        return;
    }
    double x0 = 0;

    for (int i = 0; i < wej.n; i++)
    {
        double fxp = funkcja(wej.a, wej.b, wej.c, wej.d, wej.xp);
        double fxk = funkcja(wej.a, wej.b, wej.c, wej.d, wej.xk);
        double a = (fxp - fxk) / (wej.xp - wej.xk); // wspóczynnik a funkcji g(x)
        double b = fxp - (wej.xp * a); //wyraz wolny b funkcji g(x)
        x0 = (a / -b); // miejsce zerowe funkcji g(x)
        if ((funkcja(wej.a, wej.b, wej.c, wej.d, x0) > 0 && funkcja(wej.a, wej.b, wej.c, wej.d, wej.xp) > 0) || (funkcja(wej.a, wej.b, wej.c, wej.d, x0) < 0 && funkcja(wej.a, wej.b, wej.c, wej.d, wej.xp) < 0))
        {
            wej.xp = x0;
        }
        else
        {
            wej.xk = x0;
        }

        wyj.roznica = abs(wyj.fx0 - funkcja(wej.a, wej.b, wej.c, wej.d, x0));
        if (wyj.roznica <= wej.eps)
        {
            wyj.fx0 = funkcja(wej.a, wej.b, wej.c, wej.d, x0);
            return;
        }
        wyj.fx0 = funkcja(wej.a, wej.b, wej.c, wej.d, x0);
    }
}


ostream& operator<<(ostream& str, wyjscie& wyj)
{
    if (wyj.powodzenie)
    {
        cout << "Wartosc funkcji f(x0) = " << wyj.fx0 << ", roznica w oszacowaniach: " << wyj.roznica << endl;
        return str;
    }
    else
    {
        cout << "Bledne dane!\n";
        return str;
    }
}
/* Powtarzaj n razy:
   Wyznacz parametry (wsp. kierunkowy i wyraz wolny) funkcji liniowej g(x)
       przechodz¹cej przez punkty (xp,f(xp)) i (xk,f(xk)).
       Wylicz miejsce zerowe x0 otrzymanej funkcji liniowej g(x).
       Wylicz f(x0) i
       zast¹p xp wartoœci¹ x0 jeœli f(x0) i f(xp) maj¹ ten sam znak
       w przeciwnym wypadku zast¹p xk wartoœci¹ x0.
       zwróæ ostatnie x0 (funkcja musi sygnalizowaæ powodzenie równe true) */

       /* Polecenie 2: Zmodyfikuj kod programu tak, aby agorytm koñczy³ siê jeœli ró¿nica pomiêdzy
        * dwoma kolejnymi oszacowaniami wyniku (x0) jest mniejsza od zadenego eps.
        * Zmodyfikuj tak interfejs funkcji, aby mo¿na by³o zadaæ eps, oraz zwróciæ wartoœæ f(x0) i ró¿nicê
        * w oszacowaniach (wartoœæ sparwdzan¹ w nowym kryterium zbie¿noœci).
        */

        /* Polecenie 3: Zmodyfikuj tak interfejs funkcji, aby wszytskie dane wejœciowe przekazywaæ
         * za pomoc¹ struktury, oraz wszystkie wyniki odbieraæ w postaci struktury. Napisz funkcje
         * do wype³niania struktury wejœciwem treœci¹ i do wyœwietlania struktury wyjœciowej na ekranie.
         */


int main()
{
    double a = 2.0, b = 1.0, c = -2.0, d = 1.0, poczatek = -2.0, koniec = -1.0;
    int liczbaIteracji = 10;
    double eps = 0.0001;

    wejscie  wej = { 0 };
    wyjscie  wyj = { 0 };

    podaj(wej, poczatek, koniec, a, b, c, d, liczbaIteracji, eps);
    miejsceZerowe(wej, wyj);

    cout << wyj;
}