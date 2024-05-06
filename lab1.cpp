#include <iostream>

using namespace std;

class Zamowienie {
private:
    string nazwa_produktu;
    double cena_produktu;
    string data_zakupu;
    int liczba_sztuk;

public:
    void zapisz_dane(string nazwa, double cena, string data, int liczba) {
        this->nazwa_produktu = nazwa;
        this->cena_produktu = cena;
        this->data_zakupu = data;
        this->liczba_sztuk = liczba;
    }

    void wyswietl_dane() {
        cout << "\nNazwa produktu: " << nazwa_produktu;
        cout << "\nCena produktu: " << cena_produktu;
        cout << "\nData zakupu: " << data_zakupu;
        cout << "\nLiczba sztuk: " << liczba_sztuk;
    }

    string podaj_nazwe_produktu() {
        return this->nazwa_produktu;
    }

    double podaj_cene() {
        return this->cena_produktu;
    }

    string podaj_date_zakupu() {
        return this->data_zakupu;
    }

    int podaj_liczbe_sztuk() {
        return this->liczba_sztuk;
    }

    double podaj_koszt() {
        double koszt = this->cena_produktu * this->liczba_sztuk;
        return koszt;
    }

};

int main() {
    Zamowienie zamowienie1, zamowienie2;
    string nazwa, data;
    int liczbaszt;
    double cena;

    cin >> nazwa >> cena >> data >> liczbaszt;
    
    zamowienie1.zapisz_dane(nazwa, cena, data, liczbaszt);
    zamowienie1.wyswietl_dane();
    cout << "\nKoszt zamowienia nr 1: " << zamowienie1.podaj_koszt() << endl;

    cin >> nazwa >> liczbaszt >> data >> cena;

    zamowienie2.zapisz_dane(nazwa, cena, data, liczbaszt);
    zamowienie2.wyswietl_dane();
    cout << "\nKoszt zamowienia nr 2: " << zamowienie2.podaj_koszt() << endl;
}