#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	srand(time(0));

    constexpr int x = 4, y = 7;
    int tab[x][y];

	for (int i = 0; i < x; i++)
	{
		cout << endl;
		for (int j = 0; j< y; j++)
		{
			tab[i][j] = (rand() % 8) - 2;
			cout <<setw(3)<< tab[i][j]<<" ";
		}
	}
	cout << endl;

	int nr_kolumny = 0;
	do
	{
		cout << "Podaj numer kolumny od 0 do 6: " << endl;
		cin >> nr_kolumny;
	} while (nr_kolumny >= 6 && nr_kolumny <= 0);


	int* wsk_kolumny = &tab[0][0];
	int max_wartosc = 0, nr_wiersza = 0;

	wsk_kolumny += nr_kolumny;
	max_wartosc = *wsk_kolumny;

	for (int i = 1; i < x; i++)
	{
		wsk_kolumny += 7;
		if (max_wartosc<=*wsk_kolumny)
		{
			max_wartosc = *wsk_kolumny;
			nr_wiersza = i;
		}
	}
	cout << "numer_klolumny[" << nr_kolumny << "]" << endl
		<< "numer_wiersza[" << nr_wiersza << "]" << endl;
	cout << max_wartosc;

	for (int i = 0; i < x; i++)
	{
		cout << endl;
		for (int j = 0; j < y; j++)
		{
			if (i==nr_wiersza&&j==nr_kolumny)
			{
				cout << setw(3) << "X";
			}
			else
			{
				cout << setw(3) << tab[i][j];
			}
			if (j!=6)
			{
				cout << " | ";
			}
		}
	}
	cout << endl;
	cout << "Wskaznik" << endl;

	int* wsk[x];
	for (int i = 0; i < x; i++)
	{
		wsk[i] = &tab[i][nr_kolumny];
		cout << *wsk[i]<<endl;
	}
	cout << "sortowanie";
	for (int i= 0; i < x-1; i++)
	{
		for (int j = i+1; j < x; j++)
		{
			if (*wsk[i]>*wsk[j])
			{
				int* temp = wsk[i];
				wsk[i] = wsk[j];
				wsk[j] = temp;
			}
		}
	}
	
	for (int i = 0; i < x; i++)
	{
		cout << *wsk[i] << endl;
 }
}

