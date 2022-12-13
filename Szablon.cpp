
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

//Zmieniając ostatnią literę w poniższej instrukcji na A, B, lub C wybierasz aktywne zadanie.
#define ZadanieB

#ifdef ZadanieA

void printBinary(int n, bool &exc) {
	if (n < 0) {
		//throw std::invalid_argument("Number smaller than zero");
		exc = true;
		return;
	}

	int binLenght = log2(n) + 1;

	short *res = new short[binLenght];

	for (int i = 0; i < binLenght; i++) {
		res[i] = n % 2;
		n = n / 2;
	}

	for (int i = binLenght - 1; i >= 0; i--)
		std::cout << res[i] << " ";
	std::cout << std::endl;
}

double calculatePower(double x, int n, bool& exc) {
	if (n < 0) {
		//throw std::invalid_argument("Base smaller than zero");
		exc = true;
		return 0;
	}

	if (n != 0)
		return (x * calculatePower(x, n - 1, exc));
	else
		return 1;
}

bool czy_doskonala(int n, bool& exc) {
	if (n < 0) {
		//throw std::invalid_argument("Number smaller than zero");
		exc = true;
		return 0;
	}

	int s = 1, p = sqrt(n);
	for (int i = 2; i <= p; i++)
		if (n % i == 0)
			s += i + n / i;

	if (n == p * p) s -= p;

	return n == s;
}

int main() {
	// TU ROZWIĄZUJ ZADANIE A:
	setlocale(LC_ALL, "");

	int PNTestCases[] = { 6, 10, 28, 496, -1};

	std::cout << "Czy Doskonała" << std::endl;
	for (size_t i = 0; i < (sizeof(PNTestCases) / sizeof(*PNTestCases)); i++) {
		
		bool exce = false;
		bool isper = czy_doskonala(PNTestCases[i], exce);
		if (!exce) {
			std::cout << std::boolalpha << PNTestCases[i] << " :\t" << isper << std::endl;
		}
		else {
			std::cout << PNTestCases[i] << " :" << "\tBłąd" << std::endl;
		}
	}

	
	double PowBaseCases[] = { 2.0, 3.0, 5.0 };
	int PowIndCases[] = { 2, -2, 3 };

	std::cout << std::endl << "Potęgi" << std::endl;
	for (size_t i = 0; i < (sizeof(PowBaseCases) / sizeof(*PowBaseCases)); i++) {
		
		bool exce = false;
		double res = calculatePower(PowBaseCases[i], PowIndCases[i], exce);
		
		if (!exce) {
			std::cout << "x :" << PowBaseCases[i] << " n :" << PowIndCases[i] << '\t' << " Result: " << res << std::endl;
		}
		else {
			std::cout << "x :" << PowBaseCases[i] << " n :" << PowIndCases[i] << '\t' << " Result: " << "Błąd" << std::endl;
		}
	}

	
	int ToBinCases[] = {6,10,28,-1};

	std::cout << std::endl << "Postaci Binarne" << std::endl;
	for (size_t i = 0; i < (sizeof(ToBinCases) / sizeof(*ToBinCases)); i++) {

		bool exce = false;

		std::cout << "Liczba: " << ToBinCases[i] << '\t';
		printBinary(ToBinCases[i], exce);

		if (exce)
		{
			std::cout << "Błąd" << std::endl;
		}
	}
}
#endif

#ifdef ZadanieB
// TU ROZWIĄZUJ ZADANIE B:
int cubeThrow() {
	return rand() % (10) + 1;
}

int* cubesResults(int cubeNum) {
	int* results = new int[cubeNum];
	for (size_t i = 0; i < cubeNum; i++)
		results[i] = cubeThrow();

	return results;
}

long summingCubes(int* results, int resLength, int ST) {
	long res = 0;
	for (size_t i = 0; i < resLength; i++) {
		if (results[i] == 1)
			res--;

		if (results[i] >= ST)
			res++;
	}
	return res;
}

void printingResults(int* results, int resLength) {
	std::cout << "Kostki:" << std::endl;

	for (size_t i = 0; i < resLength; i++)
		std::cout << results[i] << " ";
	std::cout << std::endl;
}

void round(int ST, int nCubes) {

	if (ST < 2 || ST > 10 || nCubes < 0) {
		std::cout << "Błędne dane";
		return;
	}

	int* cubes = cubesResults(nCubes);
	printingResults(cubes, nCubes);

	long sum = summingCubes(cubes, nCubes, ST);

	std::cout << "Suma: " << sum << std::endl;

	delete[] cubes;
}

int main()
{
	setlocale(LC_ALL, "");

	/* initialize random seed: */
	srand(time(NULL));

	int ST;
	int nCubes;

	std::cout << "Podaj ilość kostek:";
	std::cin >> nCubes;

	std::cout << "Podaj poziom trudności:";
	std::cin >> ST;

	round(ST, nCubes);
}
#endif

#ifdef ZadanieC

//wewnetrzna
long dij(int* RowI, int* RowJ, int rowLength) {
	long res = 0;

	for (size_t i = 0; i < rowLength; i++)
		res += (pow(RowJ[i] - RowI[i], 2));

	return res;
}

//zewnetrzna
void zewnetrzna(int** iarray, int arrayHeight, int arrayWidth, long& smallestDij, int& r1, int& r2) {

	r1 = 0; r2 = 1;
	smallestDij = dij(iarray[0], iarray[1], arrayWidth);

	for (size_t i = 0; i < arrayHeight; i++) {
		for (size_t x = 0; x < arrayHeight; x++) {
			if (i == x)
				continue;

			long Dij = dij(iarray[i], iarray[x], arrayWidth);

			if (Dij < smallestDij) {
				smallestDij = Dij;
				r1 = i;
				r2 = x;
			}
		}
	}
}

void printArray(int** arr, int arrayH, int arrayW) {
	for (size_t x = 0; x < arrayH; x++) {
		for (size_t y = 0; y < arrayW; y++)
			std::cout << arr[x][y] << " ";
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

int main()
{
	int arrayH = 4;
	int arrayW = 4;

	int** tab = new int* [arrayH];

	tab[0] = new int[] {1, 2, 3, 4};
	tab[1] = new int[] {5, 5, 5, 5};
	tab[2] = new int[] {1, 3, 2, 4};
	tab[3] = new int[] {6, 6, 6, 6};
	

	printArray(tab, arrayH, arrayW);

	long smallestDij;
	int r1;
	int r2;

	zewnetrzna(tab, arrayH, arrayW, smallestDij, r1, r2);

	std::cout << "Smallest Dij : " << smallestDij << std::endl;

	std::cout << "first index r1 : " << r1 << std::endl;
	std::cout << "second index r2 : " << r2 << std::endl;

	delete[] tab;
}
#endif

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

