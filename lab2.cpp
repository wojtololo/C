#include <iostream>
#include <string>
using namespace std;

class Auto {
private:
    string producent;
    string kolor;
    double pojemnosc_silnika;

public:
    Auto(string producent, string kolor, double pojemnosc) {
        this->producent = producent;
        this->kolor = kolor;
        this->pojemnosc_silnika = pojemnosc;
    }
    Auto() = default;

    string zwroc_producent() {
        return producent;
    }

    string zwroc_olor() {
        return kolor;
    }

    double zwroc_pojemnosc_silnika() {
        return pojemnosc_silnika;
    }

    void wyswietl_informacje() {
        cout << "\nProducent: " << producent;
        cout << "\nKolor: " << kolor;
        cout << "\nPojemnosc silnika: " << pojemnosc_silnika << " L";
    }
};

void wyszukaj_Auto(Auto* tablica, int rozmiar, double pojemnosc) {
    for (int i = 0; i < rozmiar; i++) {
        if (tablica[i].zwroc_pojemnosc_silnika() == pojemnosc) {
            cout << "\nZnaleziono auto: ";
            tablica[i].wyswietl_informacje();
        }
    }
}

int main() {
    Auto tab_statyczna[5] = {
        Auto("Toyota", "Czerwony", 1.6),
        Auto("Ford", "Bialy", 2.0),
        Auto("BMW", "Czarny", 3.0),
        Auto("Volkswagen", "Srebrny", 1.4),
        Auto("Mercedes", "Niebieski", 4.0)
    };

    for (int i = 0; i < 5; i++) {
        tab_statyczna[i].wyswietl_informacje();
        cout << endl;
    }

    int rozmiar;
    cout << "\nPodaj rozmiar tablicy dynamicznej: ";
    cin >> rozmiar;

    Auto* tab_dynamiczna = new Auto[rozmiar];

    for (int i = 0; i < rozmiar; i++) {
        string producent;
        string kolor;
        double pojemnosc;

        cout << "\nAuto Nr. " << i + 1;
        cout << "\nPodaj producenta: ";
        cin >> producent;
        cout << "\nPodaj kolor: ";
        cin >> kolor;
        cout << "\nPodaj pojemnosc silnika: ";
        cin >> pojemnosc;

        tab_dynamiczna[i] = Auto(producent, kolor, pojemnosc);
    }

    for (int i = 0; i < rozmiar; i++) {
        tab_dynamiczna[i].wyswietl_informacje();
    }
    
    double pojemnosc;
    cout << "\nPodaj pojemnosc silnika szukanego samochodu: ";
    cin >> pojemnosc;
    wyszukaj_Auto(tab_statyczna, 5, pojemnosc);
    wyszukaj_Auto(tab_dynamiczna, rozmiar, pojemnosc);
    delete[]tab_dynamiczna;
}
