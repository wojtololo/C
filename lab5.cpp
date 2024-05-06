#include<iostream>
#include<string>
using namespace std;
class Wektor {
	float* wspolrzedne;
	int rozmiar;
public:
	Wektor(int rozmiar) {
		this->rozmiar = rozmiar;
		wspolrzedne = new float[rozmiar];
	}
	Wektor(const Wektor& w) {
		wspolrzedne = new float[rozmiar = w.rozmiar];
		for (int i = 0; i < rozmiar; i++) {
			wspolrzedne[i] = w.wspolrzedne[i];
		}
	}
	~Wektor() {
		delete[] wspolrzedne;
	}
	void wpisz() {
		cout << "\nPodaj "<<rozmiar <<" Wspolrzedne: ";
		for (int i = 0; i < rozmiar; i++) {
			cin >> wspolrzedne[i];
		}
	}
	void info() {
		cout << "\nWspolrzedne: [";
		for (int i = 0; i < rozmiar; i++) {
			cout << " " << wspolrzedne[i];
		}
		cout << " ]";
	}
	//+++++++++
	Wektor& operator+(Wektor w1) {
		int r = rozmiar;
		Wektor* plus = new Wektor(r);
		for (int i = 0; i < r; i++) {
			plus->wspolrzedne[i] = wspolrzedne[i] + w1.wspolrzedne[i];
		}
		return *plus;
	}
	//--------
	Wektor& operator-(Wektor w1) {
		int r = rozmiar;
		Wektor* minus = new Wektor(r);
		for (int i = 0; i < r; i++) {
			minus->wspolrzedne[i] = wspolrzedne[i] - w1.wspolrzedne[i];
		}
		return *minus;
	}
	//===========
	Wektor& operator=(Wektor w) {
		if (this != &w) {
			if (rozmiar != w.rozmiar) {
				delete[] wspolrzedne;
				wspolrzedne = new float[rozmiar = w.rozmiar];
			}
			for (int i = 0; i < rozmiar; i++)
				wspolrzedne[i] = w.wspolrzedne[i];
		}
		return *this;
	}
	//skalarnie
	friend Wektor& operator*(Wektor w1, Wektor w2) {
		Wektor* skalar = new Wektor(1);
		float suma = 0;
		for (int i = 0; i < 3; i++) {
			 suma += (w1.wspolrzedne[i] * w2.wspolrzedne[i]);
		}
		skalar->wspolrzedne[0] = suma;
		return *skalar;
	}
	//mno¿enie przez liczbê
	friend Wektor& operator*(Wektor w1, int abc) {
		Wektor* skalar = new Wektor(3);
		for (int i = 0; i < 3; i++) {
			skalar->wspolrzedne[i] = w1.wspolrzedne[i] * abc;
		}
		return *skalar;
	}
	//dzielenie przez skalar
	friend Wektor& operator/(Wektor w1, Wektor w2) {
		Wektor* dziel = new Wektor(3);
		for (int i = 0; i < 3; i++) {
			dziel->wspolrzedne[i] = w1.wspolrzedne[i] / w2.wspolrzedne[i];
		}
		return *dziel;
	}
};

int main() {
//
	Wektor a(3), b(3);
	cout << "\nWektor A";
	a.wpisz();
	cout << "\nWektor B";
	b.wpisz();
//+++++++++
	Wektor c = a + b;
	cout << "\nWektor C = A + B";
	c.info();
//--------
	Wektor d = a - b;
	cout << "\nWektor D = A - B";
	d.info();
//skalarnie
	Wektor e = a * b;
	cout << "\nWektor E = A * B";;
	e.info();
//mno¿enie przez liczbê
	Wektor f = a * 3;
	cout << "\nWektor F = A * 3";
	f.info();
//dzielenie przez skalar
	Wektor g = a / b;
	cout << "\nWektor G = A / B";
	g.info();
}