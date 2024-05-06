#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;

void podslowo(string slowo_1, string slowo_2) {
	bool czy_znaleziono = false;
	string podslowo, pom_podslowo;
	for (int i = 0; i <= slowo_1.length(); i++) {
		for (int j = 0; j <= slowo_1.length(); j++) {
			for (int k = 0; k <= slowo_2.length(); k++) {
				for (int l = 0; l <= slowo_2.length(); l++) {
					if (slowo_1.substr(i, j) == slowo_2.substr(k, l)) {
						czy_znaleziono = true;
						pom_podslowo = slowo_1.substr(i, j);
						if (podslowo.length() < pom_podslowo.length()) {
							podslowo = pom_podslowo;
						}
					}
				}
			}
		}
	}
	//wyswietlenie
	if (czy_znaleziono == true) {
		cout << "\nnajdluzsze podslowo: " << podslowo;
		cout << "\nma ono dlugosc: " << podslowo.length();
	}
	else {
		cout << "nie znaleziono";
	}
}

int main(){
	string slowo_1, slowo_2;

	cout << "\nWpisz 1 slowo: ";
	cin >> slowo_1;
	while (slowo_1.length() < 1 && slowo_1.length() > 100) {
		cout << "\nWpisywane slowo moze miec maksimum 100 znakow: ";
		cin >> slowo_1;
	}

	cout << "\nWpisz 2 slowo: ";
	cin >> slowo_2;
	while (slowo_2.length() < 1 && slowo_2.length() > 100) {
		cout << "\nWpisywane slowo moze miec maksimum 100 znakow: ";
		cin >> slowo_2;
	}
	podslowo(slowo_1, slowo_2);
}