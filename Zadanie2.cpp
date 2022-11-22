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
}