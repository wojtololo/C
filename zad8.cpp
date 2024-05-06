#include <stdio.h>
#include <math.h>
#include <iostream>
#include <ctime>
#include <random>
using namespace std;

void losuj(long a[], long y) {
	default_random_engine losowa(time(0));
	uniform_real_distribution<> zakres(1, 99);
	for (int i = 0; i < y; i++) {
		int x = zakres(losowa);
		a[i] = x;
	}
}
void tab(long* a, long y) {
	int x, z, max_x = 0, max_z = 0;
	for (int i = 0; i < y; i++) {
		x = a[i];
		z = 0;
		for (int j = 0; j < y; j++) {
			if (a[j] == x) {
				z++;
			}
		}
		if (z > max_z) {
			max_x = x;
			max_z = z;
		}
	}
	cout << "\nNajczestsza wartosc to: " << max_x ;
	cout << "\nZostala wylosowana: " << max_z <<" razy";
}

int main() {
	long y = 100000;
	long* a = new long[y];
	losuj(a, y);
	tab(a, y);
}