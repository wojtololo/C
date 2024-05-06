#include <math.h>
#include <iostream>


using namespace std;
double iloraz(double a, double b, bool & error) {
    if (b == 0) {
        error = true;
    }
    else {
        return a / b;
    }

}
double pierwiastek_kwadratowy(double a, bool & error) {
    if (a < 0) {
        error = true;
    }
    else {
        return sqrt(a);
    }
}
double potega(double a, double b, bool & error) {
    if (a == 0) {
        error = true;
    }
    else {
        return pow(a, b);
    }
}
long skalarny(int a, int b, int c, int d) {
    return a * c + b * d;
}


int main() {
    int a, b, c, d;
    bool error = false;

    cout << "\n1)Iloraz\n2)Pierwiastek\n3)Potegowanie\n4)Iloczyn Skalarny"<< endl;
    cin >> a;
    if (a == 1) { //iloraz
        cout << "\nPodaj dzielna: ";
        cin >> a;
        cout << "Podaj Dzielnik: ";
        cin >> b;
        double wynik1 = iloraz(a, b, error);
        if (error == true) {
            cout << "\nNie mozna dzielic przez 0!!!";
        }
        else {
            cout << "\nwynosi: " << wynik1;
        }
    }
    else if(a == 2) {//pierwiastek
        cout << "\npierwiastek z jakiej liczby chciasz wykonac: ";
        cin >> a;
        double wynik2 = pierwiastek_kwadratowy(a, error);
        if (error == true) {
            cout << "\nNie ma pierwiastka z liczby ujemnej!!!";
        }
        else {
            cout << "\nPierwiastek z liczby: " << a << " wynosi: " << wynik2;
        }
    }
    else if(a == 3) { //potega
        cout << "\npodaj podstawe potegi: ";
        cin >> a;
        cout << "\npodaj wykladnik potegi: ";
        cin >> b;
        long wynik3 = potega(a, b, error);
        if (error == true) {
            cout << "\nPodstawa nie moze sie rownac 0!!!";
        }
        else {
            cout << "\nliczba: " << a << " podniesiona do potegi: " << b << " wynosi: " << wynik3;
        }
    }
    else if(a == 4) { //skalar
        cout << "\npodaj X wektora A: ";
        cin >> a;
        cout << "\npodaj Y wektora A: ";
        cin >> b;
        cout << "\npodaj X wektora B: ";
        cin >> c;
        cout << "\npodaj Y wektora B: ";
        cin >> d;
        long wynik4 = skalarny(a, b, c, d);
        cout << "\nIloczyn skalarny wektora A = [" << a << ", " << b << "] i wektora B = [" << c << ", " << d << "] wynosi: " << wynik4;
    }
    else {
        cout << "nie ma takeigo dzialania";
    }
}