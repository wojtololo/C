#include <stdio.h>
#include <math.h>
#include <iostream>

using namespace std;

void zliczaniex(int m = 0) {
	static int x = 0;
	if (m == 0) {
		x++;
	}
	else {
		cout << x;
		x = 0;
	}	
}

long long zad1(int a) {
	zliczaniex();
	if (a > 1) {
		return a * zad1(a - 1);
	}
	else {
		return 1;
	}
}

int zad2(int b, int c) {
	zliczaniex();
	int pom = 1;
	if (b > c) {
		pom = b - c;
	}
	else {
		pom = c - b;
	}
	if (pom == 0) {
		if (b > c) {
			return c;
		}
		else {
			return b;
		}
	}
	else {
		if (b > c) {
			b = pom;
			return zad2(b, c);
		}
		else {
			c = pom;
			return zad2(b, c);
		}
	}
}

int zad3(int b, int c) {
	zliczaniex();
	int pom = 1;
	if (b > c) {
		pom = b % c;
	}
	else {
		pom = c % b;
	}
	if (pom == 0) {
		if (b > c) {
			return c;
		}
		else {
			return b;
		}
	}
	else {
		if (b > c) {
			b = pom;
			return zad3(b, c);
		}
		else {
			c = pom;
			return zad3(b, c);
		}
	}
}

int main() {
	int a, b, c;
	cout << "Silnia z: ";
	cin >> a;
	cout << "wynosi: " << zad1(a) << ", ilosc iteracji: ";
	zliczaniex(1);
	cout << "\nNajwiekszy wspolny dzielnik liczb: " << endl;
	cin >> b >> c;
	cout << "\nWynosi: " << zad2(b, c) << ", ilosc iteracji metoda odejmowania: ";
	zliczaniex(1);
	cout << "\nWynosi: " << zad3(b, c) << ", ilosc iteracji metoda modulo: ";
	zliczaniex(1);
}