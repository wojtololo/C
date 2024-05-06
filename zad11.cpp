#include <stdio.h>
#include <cmath>
#include <iostream>
#include <ctime>
#include <random>

using namespace std;

int* stworz(int n) {
	int* tab = new int[n];
	default_random_engine losowa(time(0));
	uniform_int_distribution<> zakres(0, 100);
	for (int i = 0; i < n; i++) {
		tab[i] = zakres(losowa);
	}
	return tab;
}
void bobelkowe(int n, int* tab, int x) {
	if (x == 1) {
		for (int i = 0; i < n; i++) {
			for (int j = 1; j < n - i; j++) {
				if (tab[j - 1] > tab[j]) {
					swap(tab[j - 1], tab[j]);
					/*zamiast uzywac funkcji swap mozna dodaæ pomocnicza zmienna
					int pom = tab[j-1];
					tab[j-1] = tab[j];
					tab[j] = pom;*/
				}
			}
		}
	}
	else {
		for (int i = 0; i < n; i++) {
			for (int j = 1; j < n - i; j++) {
				if (tab[j - 1] < tab[j]) {
					swap(tab[j - 1], tab[j]);
				}
			}
		}
	}
}
void sprawdzenie(int n, int* tab, int y) {
	bool czyjest = false;
	int z;
	int ile = 0;
	for (int i = 0; i < n; i++) {
		if (tab[i] == y) {
			if (czyjest == false) {
				czyjest = true;
				z = i + 1;
			}
			ile++;
		}
	}
	if (czyjest == true) {
		cout << "\nszukana znajduje sie na: " << z << " miejscu, " << n << " elementowej tablicy" << endl;
		cout << "\npowtorzyla sie ona: " << ile << " razy";
	}
	else cout << "\nszukana nie pojawila sie w tablicy";
}



int main() {
	int n, x, y;
	cout << "\nIle tablica ma miec elemtow? : ";
	cin >> n;
	int* tab = stworz(n);

	cout << "\nSortowanie rosnaco = 1, malejaco = 2.";
	cin >> x;
	while (x != 1 && x != 2) {
		cout << "\nSortowanie rosnaco = 1, malejaco = 2.";
		cin >> x;
	}

	bobelkowe(n, tab, x);

	cout << "\njaka liczbe chcesz znalezc zakres<0, 100>: ";
	cin >> y;	
	while (y < 0 || y > 100) {
		cout << "\njaka liczbe chcesz znalezc: ";
		cin >> y;
	}

	sprawdzenie(n, tab, y);
	delete tab;
}