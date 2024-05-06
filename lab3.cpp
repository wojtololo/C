#include <iostream>
#include <string>
using namespace std;

class Silnik {
private:
    int pojemnosc;
    string producent;

public:
    Silnik() {};

    Silnik(int pojemnosc, string producent) {
        this->pojemnosc = pojemnosc;
        this->producent = producent;
    }

    int zwroc_pojemnosc_silnika() {
        return pojemnosc;
    }

    string zwroc_producenta_silnika() {
        return producent;
    }

    void wyswietl_silnik() {
        cout << "\nPojemnosc silnika: " << pojemnosc << " ccm^3";
        cout << "\nProducent silnika: " << producent;
        cout << "\n";
    }
};

class Urzadzenie {
private:
    const string producent;
    int obroty;
    Silnik silnik;

public:

    Urzadzenie() { };

    Urzadzenie(string Uproducent, int obroty, Silnik silnik)
        :producent(Uproducent), obroty(obroty), silnik(silnik)
    { }
    /*
    Urzadzenie& operator=(Urzadzenie const& o) {
        if (&o != this) {
            producent = o.producent;
            obroty = o.obroty;
            silnik = o.silnik;
        }
        return *this;
    }
    */    

    string zwroc_producent_auta() {
        return producent;
    }

    int zwroc_obroty() {
        return obroty;
    }

    Silnik zwroc_silnik() {
        return silnik;
    }

    void wyswietl_informacje() {
        cout << "\n\nProducent auta: " << producent;
        cout << "\nObroty: " << obroty << " RPM";
        zwroc_silnik().wyswietl_silnik();
    }
};
/*
Urzadzenie* znajdz(Urzadzenie* tab, int rozmiar_tab, int& liczba_wynikow) {

    Urzadzenie* wynik = new Urzadzenie[rozmiar_tab];
    int liczba = 0;
    for (int i = 0; i < rozmiar_tab; i++) {
        if (tab[i].zwroc_producent_auta() == tab[i].zwroc_silnik().zwroc_producenta_silnika()) {
            wynik[liczba] = tab[i];
            liczba++;
        }
    }
    liczba_wynikow = liczba;
    return wynik;
}
*/

void znajdz_void(Urzadzenie* tab, int rozmiar_tab) {

    for (int i = 0; i < rozmiar_tab; i++) {
        if (tab[i].zwroc_producent_auta() == tab[i].zwroc_silnik().zwroc_producenta_silnika()) {
            tab[i].wyswietl_informacje();
        }
    }
}

int main() {

    Urzadzenie  u1("Toyota", 4000, Silnik(1600, "Toyota"));
    Urzadzenie  u2("Lexus", 6000, Silnik(4000, "Toyota"));
    Urzadzenie  u3("Mini", 3000, Silnik(2000, "BMW"));
    Urzadzenie  u4("BMW", 6000, Silnik(3200, "BMW"));
    Urzadzenie  u5("Volkswagen", 5000, Silnik(1600, "Volkswagen"));
    Urzadzenie  u6("Audi", 5000, Silnik(2000, "Volkswagen"));

    Urzadzenie tab[6]{ u1, u2, u3, u4, u5, u6 };


   

    int liczba_wynikow = 0;
    cout << "\nSamochody z tym samym producentem silnika i urzadzenia: ";

    /*
    Urzadzenie* wynik = znajdz(tab, 6, liczba_wynikow);
    if (liczba_wynikow > 0) {
        for (int i = 0; i < liczba_wynikow; i++) {
            wynik[i].wyswietl_informacje();
        }
        delete[] wynik;
    }
    else {
        cout << "Nie znaleziono samochodu" << endl;
    }
    */
    
    znajdz_void(tab, 6);
}