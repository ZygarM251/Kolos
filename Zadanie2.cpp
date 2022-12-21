#include <iostream>
#include <ctime>
#include <algorithm>
using namespace std;
int main()
{
    int i = 0;
    int j = 0;
    int min = 0;
    int temp = 0;

    const int wiersz = 7;
    const int kolumna = 4;

    int tab[wiersz][kolumna] = {};

    srand(time(0));

    for (i = 0; i < wiersz; i++)
    {
        for (j = 0; j < kolumna; j++)
        {
            tab[i][j] = rand() % 15 - 9;
        }
    }
    for (i = 0; i < wiersz; i++)
    {
        for (j = 0; j < kolumna; j++)
        {
            cout << tab[i][j] << "  ";
        }
        cout << endl;
    }
    cout << "Podaj kolumne (0-3): ";
    cin >> i;
    while (i < 0 || i > 3)
    {
        cout << "Podaj poprawna licze (0-3): ";
        cin >> i;
    }
    int* wsk = &tab[0][i];
    temp = *wsk;
    for (i = 0; i < wiersz; i++)
    {
        if (*(wsk + (i * kolumna)) < temp)
        {
            temp = *(wsk + (i * kolumna));
            min = i * kolumna;
        }
    }
    cout << min << endl;
    cout << "najmniejszy element wybranej kolumny: " << temp << endl;
    for (i = 0; i < wiersz; i++)
    {
        for (j = 0; j < kolumna; j++)
        {
            if (i * (j + 1) == min)
            {
                cout << " X :";
            }
            else if (j != kolumna - 1)
            {
                if (tab[i][j] >= 0)
                {
                    cout << " " << tab[i][j] << " :";
                }
                else
                {
                    cout << tab[i][j] << " :";
                }
            }
            else
            {
                if (tab[i][j] >= 0)
                {
                    cout << " " << tab[i][j] << " ";
                }
                else
                {
                    cout << tab[i][j] << " ";
                }
            }
        }
        cout << endl;
    }
}\\

#ifdef ZadanieB

double yk(double x, double yk, double n) {
    return (1 / n) * (((n - 1) * yk) + (x / (pow(yk, n - 1))));
}

double rootStep(double x, double ykn, double n) {
    double fstep = yk(x, ykn, n);
    double Sstep = yk(x, fstep, n);

    return Sstep;
}

double root(double x, int n, double E, bool& err) {

    if (n <= 0 || x <= 0.0) {
        err = true;
        return 0;
    }

    double fstep = yk(x, x, n);
    double Sstep = yk(x, fstep, n);

    long k = 0;

    do {
        fstep = Sstep;

        double temp = rootStep(x, fstep, n);
        Sstep = temp;

        k++;

        //std::cout << abs(Sstep - fstep)<<std::endl;

        if (k < 3)
            continue;

    } while (abs(Sstep - fstep) >= E);

    return Sstep;
}


int main()
{
    // TU ROZWIĄZUJ ZADANIE B:
    //startowo yk = x

    double x;
    int n;
    double E;

    std::cout << "Podaj x:";
    std::cin >> x;

    std::cout << "Podaj n:";
    std::cin >> n;

    std::cout << "Podaj E:";
    std::cin >> E;

    bool err = false;
    double res = root(x, n, E, err);

    if (!err)
        std::cout << "Result: " << res;
    else
        std::cout << "Result: " << "Error :(";
}
#endif

#ifdef ZadanieB
double obliczenia(double x, int n, double dokladnosc)
{
    //double y = pow(x, 1/n);
    double y; //yk
    double drugiy = x; //yk+1
    do
    {
        y = drugiy;
        drugiy = (1.0 / n) * ((n - 1.0) * y + x / pow(y, n - 1.0));

    } while (abs((drugiy - y)) > dokladnosc);
    return y;
}
int main()
{
    setlocale(LC_ALL, "");
    int n;
    double x, dokladnosc;
    cout << "Podaj liczbę pierwiastkowaną x: ";
    cin >> x;
    cout << "Podaj stopień pierwiastka n: ";
    cin >> n;
    cout << "Podaj dokładność obliczeń: ";
    cin >> dokladnosc;
    if (n > 0 && x > 0.0)
    {
        double wynik = obliczenia(x, n, dokladnosc);
        cout << "Wartość y wynosi: " << wynik << endl;
    }
    else
    {
        cout << "Podano nieprawidłową wartość x lub n - BŁĄD PROGRAMU!";
    }
}
#endif