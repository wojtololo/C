#include <iostream>
#include <stdio.h>

using namespace std;

int a(char* tablica, int n) {
	int liczba_znakow = 0;
	for (int i = 0; i < n; i++) {
		if(tablica[i]){
			liczba_znakow++;
		}
		else {
			break;
		}
	}
	return liczba_znakow;
}
int b(char* tablica, int n, char znak){
	int wskazanych_liczba_znakow = 0;
	for (int i = 0; i < n; i++) {
		if (tablica[i] == znak) {
			wskazanych_liczba_znakow++;
		}
	}
	return wskazanych_liczba_znakow;
}
void c(char* tablica, int n, char znak) {
	for (int i = 0; i < n; i++) {
		if (tablica[i] == znak) {
			tablica[i] = '\0';
		}
	}
	cout << "\nTablica po usunieciu znakow: ";
	for (int i = 0; i < n; i++) {
		cout << tablica[i];
	}

}
void d(char* tablica, int n) {
	char odwrocona[50]; int j = 0;
	for (int i = n-1; i >= 0; i--) {
		cout << tablica[i];		
	}	
}
int main() {
	int n = 49; char znak;
	char* tablica =  new char [n];

	cout << "\nWpisz ciag: ";	
	cin >> tablica;	

	cout << "\n\nPodpunkt a: \n";
	cout << a(tablica, n);
	n = a(tablica, n);
	
	cout << "\n\nPodpunkt b: ";
	cout << "\nWpisz znaki ktore chcesz znalezc: ";
	cin >> znak;
	cout << b(tablica, n, znak);

	cout << "\n\nPodpunkt c: ";
	cout << "\nWpisz znaki ktore chcesz usunac: ";
	cin >> znak;
	c(tablica, n, znak);

	cout << "\n\nPodpunkt d: ";
	d(tablica, n);
	
}