#include <stdio.h>
#include <cmath>
#include <iostream>
#include <ctime>
#include <random>

using namespace std;

long stworz(long x) {
	long* a = new long[x];
	default_random_engine losowa(time(0));
	uniform_int_distribution<> zakres(0, 500);
	for (int i = 0; i < x; i++) {
		a[i] = zakres(losowa);
	}
	return a;
}
double zad_a(long* a, long x) {
	double y = 0;
	for (int i = 0; i < x; i++) {
		y += a[i];
	};
	return y/x;
}
double zad_b(long* a, long x, double y) {
	double dzielna, suma = 0;
	for (int i = 0; i < x; i++) {
		dzielna = pow(a[i] - y, 2);
		suma = +dzielna;
	}
	return sqrt(suma/x);
}

long* zad_c(long* a, long x, double y, double z) {
	int k = 0;
	for (int i = 0; i < x; i++) {
		if (a[i] > y-z && a[i] < y+z) {
			k++;
		}
	}
	long* b = new long[k];
	int j = 0;
	while (j < k) {
		for (int i = 0; i < x; i++) {
			if (a[i] > y - z && a[i] < y + z) {
				b[j] = a[i];
				j++;
			}
		}
	}
	return b;
}

long* zad_d(long* a, long x, double y) {
	long w = x / 2;
	long k = 2;
	long** c = new long*[w];
	for (int i = 0; i < w; i++) {
		c[i] = new long[k];
	}
	for (int i = 0; i < w; i++) {
			if (a[i] < y) {
				c[i][0] = a[i];
				c[i][1] = 0;
			}
			else {
				c[i][0] = 0;
				c[i][1] = a[i];
			}
	}
	return c;
}
void wyswietl(long* a, long* b, long** c, long x, double y, double z) {
	cout << "\n\nTablica a: \n\n";
	for (int i = 0; i < x; i++) {
		cout <<"[" << a[i] << "] ";
	}
	cout << "\n\nTablica b: \n\n";
	int k = 0;
	for (int i = 0; i < x; i++) {
		if (a[i] > y - z && a[i] < y + z) {
			k++;
		}
	}
	for (int i = 0; i < k; i++) {
		cout << "[" << b[i] << "] ";
	}
	cout << "\n\nTablica c: \n\n";
	for (int i = 0; i < x/2; i++) {
		cout << "\n[" << c[i][0] <<"], [" << c[i][1] << "]";
	}
}

int main() {
	long x;
	cout << "\n Ilu elementowa ma byc tablica: ";
	cin >> x;
	long* a = stworz(x);
	double y = zad_a(a, x);
	cout << "\n Srednia wartosc tablicy to: " << y ;
	double z = zad_b(a, x, y);
	cout << "\n Wartosc odchylenia standardowego to: " << z;
	long* b = zad_c(a, x, y, z);
	long* c = zad_d(a, x, y);
	wyswietl(a, b, c, x, y, z);
}