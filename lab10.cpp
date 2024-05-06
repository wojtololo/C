#include <iostream>
#include <cstring>
using namespace std;

class Nazwisko {
private:
	char* nazwisko;
public:
	Nazwisko(const char* na) {
		nazwisko = new char[strlen(na) + 1];
		strcpy_s(nazwisko, strlen(na) + 1, na);
		cout << "\nNazwisko: " << nazwisko;
	}
	~Nazwisko() {
		cout << "\nDestruktor Nazwisko: " << nazwisko;
		delete[] nazwisko;
	}

};
class Pelne :public Nazwisko {
private:
	char* imie;
public:
	Pelne(const char* im, const char* n) :Nazwisko(n) {
		imie = new char[strlen(im) + 1];
		strcpy_s(imie, strlen(im) + 1, im);
		cout << "\nImie: " << imie;
	}
	~Pelne() {
		cout << "\nDestruktor Pelne: " << imie;
		delete[] imie;
	}
};
int main() {
	
	Nazwisko* nazwisko;
	nazwisko = new Pelne("Michal", "Jedrula");
	delete nazwisko;
	cout << endl;
	nazwisko = new Pelne("Marek", "Grechuta");
	delete nazwisko;
	cout << endl;
}