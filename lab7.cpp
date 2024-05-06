#include <iostream>
#include<fstream>
#include<string>
using namespace std;

class Sprzet {
private:
	string id_s;
	string typ;
public:
	Sprzet(){}
	Sprzet(string id_s, string typ) {
		this->id_s = id_s;
		this->typ = typ;
	}
	string zwroc_id_s() {
		return id_s;
	}
	string zwroc_typ() {
		return this->typ;
	}
	void wyswietl() {
		cout << "ID: " << this->id_s << ", Typ: " << typ << endl;
	}
};
class Osoba {
private:
	string id_o;
	string nazwisko;
	int wiek;
public:
	
	Osoba(string id_o, string nazwisko, int wiek) {
		this->id_o = id_o;
		this->nazwisko = nazwisko;
		this->wiek = wiek;
	}
	Osoba() {}
	string zwroc_id_o() {
		return id_o;
	}
	string zwroc_nazwisko() {
		return nazwisko;
	}
	int zwroc_wiek() {
		return this->wiek;
	}
	void wyswietl() {
		cout << "ID: " << this->id_o << ", Nazwisko: " << nazwisko << ", wiek: " << wiek << endl;
	}
};
class Wypozyczenie {
private:
	string id_s;
	string id_o;
public:
	Wypozyczenie(){}
	Wypozyczenie(string id_s, string id_o) {
		this->id_s = id_s;
		this->id_o = id_o;
	}
	string zwroc_id_s() {
		return id_s;
	}
	string zwroc_id_o() {
		return id_o;
	}
	void wyswietl() {
		cout << "ID_S: " << this->id_s << ", ID_O: " << id_o << endl;
	}
};

void zapis(Sprzet* tab_S, Osoba* tab_O, Wypozyczenie* tab_W, int n) {
	ofstream zapis("dane.txt");
	for (int i = 0; i < n; i++) {
		zapis << tab_S[i].zwroc_id_s() << " " << tab_S[i].zwroc_typ() << endl;
	}

	for (int i = 0; i < n; i++) {
		zapis << tab_O[i].zwroc_id_o() << " " << tab_O[i].zwroc_nazwisko() << " " << tab_O[i].zwroc_wiek() << endl;
	}

	for (int i = 0; i < n; i++) {
		zapis << tab_W[i].zwroc_id_o() << " " << tab_W[i].zwroc_id_s() << endl;
	}

	zapis.close();
}

void odczyt(Sprzet* Sprzety_1, Osoba* Osoby_1, Wypozyczenie* Wypozyczenia_1, int n) {
	string dane1, dane2;
	int wiek;
	ifstream zpliku("dane.txt");
	if (zpliku.is_open()) {

		for (int i = 0; i < n; i++) {
			zpliku >> dane1 >> dane2;
			Sprzety_1[i] = Sprzet(dane1, dane2);
		}
		for (int i = 0; i < n; i++) {
			zpliku >> dane1 >> dane2 >> wiek;
			Osoby_1[i] = Osoba(dane1, dane2, wiek);
		}
		for (int i = 0; i < n; i++) {
			zpliku >> dane1 >> dane2;
			Wypozyczenia_1[i] = Wypozyczenie(dane1, dane2);
		}
		zpliku.close();
	}
	else cout << "blad pliku!";
}


Osoba* zad3(Sprzet* tab_S, Osoba* tab_O, Wypozyczenie* tab_W, int rozmiar, int & licznik) {
	Osoba* tablica = new Osoba[rozmiar];
	int indeks = 0;

	for (int i = 0; i < rozmiar; i++) {
		if (tab_O[i].zwroc_wiek() > 25) {
			for (int j = 0; j << rozmiar; j++) {
				if (tab_S[j].zwroc_typ() == "hulajnoga") {
					for (int k = 0; k << rozmiar; k++) {
						if (tab_W[k].zwroc_id_s() == tab_S[j].zwroc_id_s() && tab_W[k].zwroc_id_o() == tab_O[i].zwroc_id_o()) {
							tablica[indeks] = tab_O[i];
							indeks++;
							licznik++;
						}
					}
				}
			}
		}
	}
	return tablica;
}

int liczba_rowerow(Sprzet* tab_S, int rozmiar) {
	int suma = 0;
	for (int i = 0; i < rozmiar; i++) {
		if (tab_S[i].zwroc_typ() == "rower") {
			suma++;
		}
	}
	return suma;
}

int main() {
	Sprzet tab_S[6]{
		Sprzet("S1", "rower"),
		Sprzet("S2", "hulajnoga"),
		Sprzet("S3", "rolki"),
		Sprzet("S4", "rower"),
		Sprzet("S5", "hulajnoga"),
		Sprzet("S6", "rolki"),
	};
	Osoba tab_O[6]{
		Osoba("O1", "Kowalski", 26),
		Osoba("O2", "Nowak", 28),
		Osoba("O3", "Mazur", 29),
		Osoba("O4", "Wisniewski", 30),
		Osoba("O5", "Wojcik", 35),
		Osoba("O6", "Lewandowski", 40),
	};
	Wypozyczenie tab_W[6]{
		Wypozyczenie("S6", "O5"),
		Wypozyczenie("S1", "O6"),
		Wypozyczenie("S2", "O1"),
		Wypozyczenie("S3", "O2"),
		Wypozyczenie("S4", "O3"),
		Wypozyczenie("S5", "O4"),
	};	

	int rozmiar = 6;
	//zad1
	zapis(tab_S, tab_O, tab_W, rozmiar);

	//zad2

	Sprzet* Sprzety_1 = new Sprzet[rozmiar];
	Osoba* Osoby_1 = new Osoba[rozmiar];
	Wypozyczenie* Wypozyczenia_1 = new Wypozyczenie[rozmiar];	
	odczyt(Sprzety_1, Osoby_1, Wypozyczenia_1, rozmiar);	

	// wyswietlenie
	cout << "\nSprzety:\n";
	for (int i = 0; i < rozmiar; i++) {
		Sprzety_1[i].wyswietl();
	}
	cout << "\nOsoby:\n";
	for (int i = 0; i < rozmiar; i++) {
		Osoby_1[i].wyswietl();
	}
	cout << "\nWypozyczenia:\n";
	for (int i = 0; i < rozmiar; i++) {
		Wypozyczenia_1[i].wyswietl();
	}

	//zad3
	int licznik = 0;
	cout << "\nzad3: \n";
	Osoba *tabzad3 = zad3(tab_S, tab_O, tab_W, rozmiar, licznik);
	if (licznik > 0) {
		for (int i = 0; i < licznik; i++) {
			tabzad3[i].wyswietl();
		}
	}

	//zad4
	cout << "\n\nzad4: \n";
	cout << "Liczba wypozyczonych rowerow: " << liczba_rowerow(Sprzety_1, rozmiar);
	cout << "\n";
}