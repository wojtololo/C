using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Samochody
{
    class Samochod
    {
        public int rocznik;
        public int nr_s;
        public string producent;
        public bool przeglad;
        public virtual void wypisz_Dane()
        {
            Console.WriteLine("rocznik " + rocznik + "  producent: " + producent);
        }
        public Samochod(int rocznik, int nr_s, string producent, bool przeglad)
        {
            this.rocznik = rocznik;
            this.nr_s = nr_s;
            this.producent = producent;
            this.przeglad = przeglad;
        }
        public Samochod()
        {
        }
    }
    class Osobowy : Samochod
    {
        public int liczba_d;
        public override void wypisz_Dane()
        {
            Console.WriteLine("rocznik " + rocznik + "producent: " + producent + "liczba_d " + liczba_d);
        }
        public Osobowy(int rocznik, int nr_s, string producent, bool przeglad, int liczba_d)
        {
            this.rocznik = rocznik;
            this.nr_s = nr_s;
            this.producent = producent;
            this.przeglad = przeglad;
            this.liczba_d = liczba_d;
        }
        public Osobowy()
        {
        }
    }
    class Ciezarowka : Samochod
    {
        public int ladownosc;
        public override void wypisz_Dane()
        {
            base.wypisz_Dane();
            Console.WriteLine("ladownosc:  " + ladownosc);
        }
        public Ciezarowka() { }
        public Ciezarowka(int rocznik, int nr_s, string producent, bool przeglad, int ladownosc)
        {
            this.rocznik = rocznik;
            this.nr_s = nr_s;
            this.producent = producent;
            this.przeglad = przeglad;
            this.ladownosc = ladownosc;
        }

    }
    class EwidencjaS
    {
        List<Samochod> L;
        public void wstaw(Samochod s)
        {
            L.Add(s);
        }
        public void info()
        {
            foreach (Samochod s in L)
            { s.wypisz_Dane(); }
        }
        //klasa pomocnicza
        public void wypisz_wszystkie()
        {
            foreach (Samochod s in L)
            {
                s.wypisz_Dane();
            }
        }
        //zad3
        public void znajdz1(int ładunek)
        {
            int suma = 0;
            bool czy_bylo = false;
            EwidencjaS F = new EwidencjaS();
            foreach (Samochod s in L)
            {
                if (s is Ciezarowka)
                {
                    if (s.przeglad && (s as Ciezarowka).ladownosc > 0)
                    {
                        suma +=(s as Ciezarowka).ladownosc;
                        F.wstaw(s);
                        if (suma > ładunek)
                        {
                            czy_bylo = true;
                            Console.WriteLine("Lista ciężarówek których wspólna ładowność przekracza: "+ ładunek);
                            F.wypisz_wszystkie();
                            break;
                        }
                    }
                }
            }
            if (!czy_bylo)
            {
                Console.WriteLine("Ładunek przekracza ładowność wszystkich twoich ciężarówek");
            }
        }
        public void Pokaz(int n)
        {
            foreach (Samochod s in L)
            {
                if (s is Ciezarowka)
                {
                    if (s.przeglad && (s as Ciezarowka).ladownosc > n)
                    {
                        s.wypisz_Dane();
                    }
                }
            }
        }
        public EwidencjaS() { L = new List<Samochod>(); }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Samochod S = new Samochod(2000, 100, "Fiat", true);
            Osobowy O = new Osobowy(2001, 101, "Passat", false, 4);
            Ciezarowka C1 = new Ciezarowka(2005, 200, "Man", true, 1500);
            Ciezarowka C2 = new Ciezarowka(2010, 203, "Renault", false, 1000);
            Ciezarowka C3 = new Ciezarowka(2011, 202, "Mercedes", true, 2001);
            Ciezarowka C4 = new Ciezarowka(2012, 201, "Scania", true, 1750);

            EwidencjaS E = new EwidencjaS();
            E.wstaw(S); E.wstaw(O); E.wstaw(C1); E.wstaw(C2); E.wstaw(C3); E.wstaw(C4);

            E.znajdz1(3000);


            Console.WriteLine("Koniec");
            Console.ReadLine();

        }
    }
}
