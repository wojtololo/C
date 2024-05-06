#include <iostream>
#include <math.h>

using namespace std;

double pi = 3.14;

class Bryla {
public:
	virtual void objetosc() {
		cout << "\nnieokreslony";
	}
	virtual void pole_powierzchni_calkowitej() {
		cout << "\nnieokreslony";
	}
	virtual void pobierz_dane() {
		cout << "\nnieokreslony";
	}
};
class Stozek :public Bryla {
private:
	int r;
	int h;
	int l;
public:
	Stozek(int r, int h, int l) {
		this->r = r;
		this->h = h;
		this->l = l;
	}
	void objetosc() {
		cout << "\nObjetosc Stozka: " << (pi * pow(r, 2) * h) / 3;
	}
	void pole_powierzchni_calkowitej() {
		cout << "\nPole Powierzchni Stozka: " << pi * r * (r+l);
	}
	void pobierz_dane() {
		cout << "\n\nStozek: ";
		cout << "\nPromien: " << r;
		cout << "\nWysokosc: " << h;
		cout << "\nKrawedz boczna: " << l;
		objetosc();
		pole_powierzchni_calkowitej();
	}
};
class Walec :public Bryla {
private:
	int r;
	int h;
public:
	Walec(int r, int h) {
		this->r = r;
		this->h = h;
	}

	void objetosc() {
		cout << "\nObjetosc Walca: " << pi * pow(r, 2) * h;
	}
	void pole_powierzchni_calkowitej() {
		cout << "\nPole Powierzchni Walca: " << 2 * pi * r *(r + h);
	}
	void pobierz_dane() {
		cout << "\n\nWalec: ";
		cout << "\nPromien: " << r;
		cout << "\nWysokosc: " << h;
		objetosc();
		pole_powierzchni_calkowitej();
	}
};
class Kula :public Bryla {
private:
	int r;
public:
	Kula(int r) {
		this->r = r;
	}
	void objetosc() {
		cout << "\nObjetosc Kuli: " << (4*pi*pow(r, 3))/3;
	}
	void pole_powierzchni_calkowitej() {
		cout << "\nPole Powierzchni Kuli: " << 4*pi * pow(r, 2);
	}
	void pobierz_dane() {
		cout << "\n\nKula: ";
		cout << "\nPromien: " << r;
		objetosc();
		pole_powierzchni_calkowitej();
	}
};
class Czworoœcian_Foremny :public Bryla {
private:
	int a;
public:
	Czworoœcian_Foremny(int a) {
		this->a = a;
	}
	void objetosc() {
		cout << "\nObjetosc Czworoscianu Foremnego: "<< (pow(a, 3) * sqrt(2))/12;
	}
	void pole_powierzchni_calkowitej() {
		cout << "\nPole Powierzchni Czworoscianu Foremnego: " << pow(a, 2) * sqrt(3);
	}
	void pobierz_dane() {
		cout << "\n\nCzworoscian Foremny: ";
		cout << "\nBok: " << a;
		objetosc();
		pole_powierzchni_calkowitej();
	}
};
class Prostopadloœcian :public Bryla {
private:
	int a;
	int b;
	int h;
public:
	Prostopadloœcian(int a, int b, int h) {
		this->a = a;
		this->b = b;
		this->h = h;
	}
	void objetosc() {
		cout << "\nObjetosc Prostopadloscianu: " << a*b*h;
	}
	void pole_powierzchni_calkowitej() {
		cout << "\nPole Powierzchni Prostopadloscianu: "<< 2*(a*b + a*h + b*h);
	}
	void pobierz_dane() {
		cout << "\n\nProstopaldoscian: ";
		cout << "\nBok A: " << a;
		cout << "\nBok B: " << b;
		cout << "\nWysokosc: " << h;
		objetosc();
		pole_powierzchni_calkowitej();
	}
};
void wywolanie(Bryla & b) {
	b.pobierz_dane();
}
int main() {
	Stozek s(3, 4, 5);
	Walec w(7, 6);
	Kula k(8);
	Czworoœcian_Foremny c(9);
	Prostopadloœcian p(10, 11, 12);

	wywolanie(s);
	wywolanie(w);
	wywolanie(k);
	wywolanie(c);
	wywolanie(p);
}