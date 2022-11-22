#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

int main()
{
	srand(time(NULL));

	const int wiersze = 5;
	const int kolumny = 5;

	int tablica[wiersze][kolumny] = {};

	for (int wier = 0; wier < 5; wier++)
	{
		for (int kol = 0; kol < 5; kol++)
		{
			tablica[wier][kol] = (rand() % 12) - 2;
		}

	}

	for (int i = 0; i < 5; i++)
	{

		for (int j = 0; j < 5; j++)
		{
			cout << setw(3) << tablica[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl;
	int i;
	do {
		cout << "Podaj kolumne do posortowania: ";
		cin >> i;
	} while (i <= -1 ||i >= 5);

	int* wsk = &tablica[0][i];

	for (int i = 0; i < kolumny; i++)
	{
		for (int j = i + 1; j < kolumny; j++)
		{
			if (*(wsk + (i * wiersze)) > *(wsk + (j * wiersze)))
			{
				int sort = *(wsk + (i * wiersze));
				*(wsk + (i * wiersze)) = *(wsk + (j * wiersze));
				*(wsk + (j * wiersze)) = sort;
			}
		}
	}

	for (int i = 0; i < wiersze; i++)
	{
		for (int j = 0; j < kolumny; j++)
		{
			if (j != kolumny - 1)
			{
				if (tablica[i][j] >= 0)
				{
					cout << " " << tablica[i][j] << " |";
				}
				else
				{
					cout << tablica[i][j] << " |";
				}
			}
			else
			{
				if (tablica[i][j] >= 0)
				{
					cout << " " << tablica[i][j] << " ";
				}
				else
				{
					cout << tablica[i][j] << " ";
				}
			}

		}
		cout << endl;

	}

}