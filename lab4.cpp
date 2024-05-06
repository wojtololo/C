#include <iostream>

using namespace std;

class Auto {
private:
	string nazwa;
	int max_predkosc;
public:
	Auto() {}
	Auto(string nazwa, int max_predkosc)
		:nazwa(nazwa), max_predkosc(max_predkosc)
	{ }
	void info() {
		cout << "\nNazwa auta: " << nazwa;
		cout << "\nPredkosc maksymalna: " << max_predkosc;
	}
};

class Samolot {
private:
	string nazwa;
	int max_predkosc;
public:
	Samolot() {}
	Samolot(string nazwa, int max_predkosc)
		:nazwa(nazwa), max_predkosc(max_predkosc)
	{ }
	void info() {
		cout << "\nNazwa samolotu: " << nazwa;
		cout << "\nPredkosc maksymalna: " << max_predkosc;
	}
};

template <typename T>
class Stos {
private:
	const int Max_rozmiar;
	T* stos_obj;
	int rozmiar;

public:
	Stos(int Max_rozmiar) : Max_rozmiar(Max_rozmiar), rozmiar(0), stos_obj(new T[Max_rozmiar])
	{	}
	void polozenie(T obiekt) {
		if (rozmiar > Max_rozmiar - 1) {
			cout << "\nPrzekroczenie rozmiaru tablicy!!";
		}
		stos_obj[rozmiar] = obiekt;
		rozmiar++;
	}
	void zdjecie(int indeks) {
		for (int i = indeks; i < rozmiar; i++) {
			stos_obj[i - 1] = stos_obj[i];
		}
		rozmiar--;
	}
	void oproznienie() {
		if (rozmiar == Max_rozmiar) {
			delete[] stos_obj;
			rozmiar = 0;
		}
	}
	bool czy_pusty() {
		return rozmiar == 0;
	}
	int r_rozmiar() {
		return rozmiar;
	}
	T zworc(int indeks) {
		return stos_obj[indeks];
	}

};
template<class T>
void wyswietlanie(Stos<T>& typ) {
	if (typ.czy_pusty()) {
		cout << "\nStos jest pusty";
	}
	else {
		for (int i = 0; i < typ.r_rozmiar(); i++) {
			typ.zworc(i).info();
		}
	}
	cout << "\n";
}

int main() {

	Stos<Auto> auta(5);
	Stos<Samolot> samoloty(5);

	auta.polozenie(Auto("Toyota", 200));
	auta.polozenie(Auto("Lexus", 230));
	auta.polozenie(Auto("Mini", 180));
	auta.polozenie(Auto("BMW", 250));
	auta.polozenie(Auto("Audi", 280));	

	samoloty.polozenie(Samolot("Boeing 747", 920));
	samoloty.polozenie(Samolot("Airbus A380", 1020));
	samoloty.polozenie(Samolot("F-22 Raptor", 2410));
	samoloty.polozenie(Samolot("Concorde", 2200));
	samoloty.polozenie(Samolot("Su-57", 2440));

	cout << "\n\nWyswietlenie stosow:\n";
	wyswietlanie(auta);
	wyswietlanie(samoloty);

	cout << "\n\nzdjecie 1 obiektu ze stosu:\n";
	auta.zdjecie(1);	
	wyswietlanie(auta);

	cout << "\n\nOproznienie stosu samoloty:\n";
	samoloty.oproznienie();
	wyswietlanie(samoloty);
}