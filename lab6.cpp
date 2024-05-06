#include <iostream>
#include <cstring>

using namespace std;

int n = 20;

class Osoba {
private:
    char* imie;
    char* nazwisko;
    int wiek;

public:
    Osoba(const char* imie_, const char* nazwisko_, int wiek_) {
        imie = new char[n];
        for (int i = 0; i < n; i++) {
            imie[i] = imie_[i];
        }
        nazwisko = new char[n];
        for (int i = 0; i < n; i++) {
            nazwisko[i] = nazwisko_[i];
        }
        wiek = wiek_;
    }
    Osoba(const Osoba& w) {
        imie = new char[n];
        for (int i = 0; i < n; i++) {
            imie[i] = w.imie[i];
        }
        nazwisko = new char[n];
        for (int i = 0; i < n; i++) {
            nazwisko[i] = w.nazwisko[i];
        }
        wiek = w.wiek;
    }    
    ~Osoba() {
        delete[] imie;
        delete[] nazwisko;
    }
    void pokaz() {
        cout << "\n\nImie: " << imie;
        cout << "\nNazwisko: " << nazwisko;
        cout << "\nWiek: " << wiek;
    }
    void zmien_imie(const char* imie_) {
        delete[] imie;
        imie = new char[20];
        for (int i = 0; i < n; i++) {
            imie[i] = imie_[i];
        }
    }
};

int main() {
    Osoba osoba1("Piotr", "Kowalski", 30);
    Osoba osoba2 = osoba1;

    //je¿eli nie damy konstruktora kopiuj¹cego obiekt
    //obiekt 1 bêdzie dzieli³ tablicê z obiektem 2

    Osoba osoba3(osoba1);

    osoba2.zmien_imie("Pawel");
    osoba3.zmien_imie("Kamil");

    osoba1.pokaz();
    osoba2.pokaz();
    osoba3.pokaz();
}
