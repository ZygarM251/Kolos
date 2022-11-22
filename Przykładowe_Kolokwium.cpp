#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    int n,licznik=0,wypisanie=0,liczby=1,ilosc_liczb=0,suma=0,iloczyn=1,s=0,g=0;
    do {
        cout << "Podaj liczby";
        cin >> n;
        wypisanie += n*liczby;
        if (n%2==0)
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
        
    } while (licznik!=3);
    cout << wypisanie<<endl;
    cout << suma << endl;
    cout << iloczyn << endl;
    
    s = suma / ilosc_liczb;
    g = pow(iloczyn, 1.0 / ilosc_liczb);
    cout << "Średnia arytmetyczna wynosi: " << s << endl;
    cout << "Średnia geometryczna wynosi: " << g << endl;

    double e = 2.7182;
    int funkcja = 0;
    funkcja = pow(s, e) * log10(g - 1 / g + 1);
    cout << scientific <<setprecision(8) << "Funkcja wynosi: " << funkcja;

}

