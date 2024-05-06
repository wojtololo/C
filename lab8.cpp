#include <iostream>

using namespace std;

class Urzadzenie {
	protected:
		string firma;
		int obroty;
	public:
		Urzadzenie(){}
		Urzadzenie(string firma, int obroty) {
			this->firma = firma;
			this->obroty = obroty;
		}
		string daj_firme() {
			return firma;
		}
		int daj_obroty() {
			return obroty;
		}
		void pokaz_opis() {
			cout << "\nProducent: " <<this->firma;
			cout << "\nObroty: " <<this->obroty << "na minute";
		}
};
class SzlifierkaKatowa : public Urzadzenie {
	private:
		int moc;
		int tarcza;
	public:
		SzlifierkaKatowa(){}
		SzlifierkaKatowa(string firma, int obroty, int moc, int tarcza) {
			this->firma = firma;
			this->obroty = obroty;

			this->moc = moc;
			this->tarcza = tarcza;
		}
		int daj_moc() {
			return moc;
		}
		int daj_tarcze() {
			return tarcza;
		}
		void pokaz_opis() {
			cout << "\nProducent: " << this->firma;
			cout << "\nObroty " << this->obroty << " na minute";

			cout << "\nMoc: " << this->moc << " W";
			cout << "\nSrednica tarczy: " << this->tarcza << " [mm]";
		}
};
class WiertarkoWkretarka : public Urzadzenie {
	private:
		double napiecie;
		string bateria;
		int czas_ladow;
	public:
		WiertarkoWkretarka(){}
		WiertarkoWkretarka(string firma, int obroty, double napiecie, string bateria, int czas_ladow) {
			this->firma = firma;
			this->obroty = obroty;

			this->napiecie = napiecie;
			this->bateria = bateria;
			this->czas_ladow = czas_ladow;
		}
		double daj_napiecie() {
			return napiecie;
		}
		string daj_baterie() {
			return bateria;
		}
		int daj_czas_ladow() {
			return czas_ladow;
		}
		void pokaz_opis() {
			cout << "\nProducent: " << this->firma;
			cout << "\nObroty " << this->obroty<< " na minute";

			cout << "\nNapiecie: " << this->napiecie;
			cout << "\nTyp Baterii: " << this->bateria;
			cout << "\nCzas ladowania: " << this->czas_ladow << " [min]";
		}
};

WiertarkoWkretarka najkrotszy(WiertarkoWkretarka *tab, int n) {
	int czas = 999;
	int tmp;
	for (int i = 0; i < n; i++) {
		if (tab[i].daj_czas_ladow() < czas) {
			czas = tab[i].daj_czas_ladow();
			tmp = i;
		}
	}
	return tab[tmp];
}

SzlifierkaKatowa najwieksze(SzlifierkaKatowa *tab, int n) {
	int najwy = 0;
	int tmp;
	for (int i = 0; i < n; i++) {
		if (tab[i].daj_obroty() > najwy) {
			najwy = tab[i].daj_obroty();
			tmp = i;
		}
	}
	return tab[tmp];
}

int main() {
	SzlifierkaKatowa tab_s[4]{
		SzlifierkaKatowa("Bosh", 2500, 200, 150),
		SzlifierkaKatowa("Black&Decker", 3000, 300, 420),
		SzlifierkaKatowa("Makita", 3500, 400, 300),
		SzlifierkaKatowa("Parkside", 2800, 250, 200),
	};
	WiertarkoWkretarka tab_w[4]{
		WiertarkoWkretarka("Bosh", 2500, 2.30, "Litowo-jonowa", 60),
		WiertarkoWkretarka("Black&Decker", 3300, 3.33, "Polimerowa", 40),
		WiertarkoWkretarka("Makita", 3000, 3.13, "Litowo-Polimerowa", 120),
		WiertarkoWkretarka("Parkside", 2600, 2.88, "O³owioa", 80),
	};
	
	SzlifierkaKatowa Top_Obroty = najwieksze(tab_s, 4);
	WiertarkoWkretarka Min_czas = najkrotszy(tab_w, 4);

	cout << "\n\nSzlifierka o najwyzszych obrotach: ";
	Top_Obroty.pokaz_opis();
	cout << "\n\nWiertako-Wkretarka o najkrotszym czasie ladowania: ";
	Min_czas.pokaz_opis();
}