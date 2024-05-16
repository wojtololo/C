using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GrafProsty
{
    class Graf
    {
        public int n;
        public bool[] marked;
        public List<int>[] S;
        public List<int> sasiedzi(int k) { return S[k]; }
        public void zaznacz(int k) { marked[k] = true; }
        public void usun_zaznaczenia()
        {
            for (int i = 1; i <= n; i++) marked[i] = false;
        }
        public bool zaznaczony(int k) { return marked[k]; }
        public void DFS(int k)
        {
            List<int> L = S[k];
            foreach (int w in L)
            {
                if (!zaznaczony(w))
                {
                    zaznacz(w);
                    Console.WriteLine("Kolejny odwiedzony   " + w);
                    DFS(w);
                }
            }
        }
        public void wczytaj_graf()
        {
            Console.Write("Podaj liczbe wierzcholkow grafu n=");
            n = Convert.ToInt16(Console.ReadLine());
            marked = new bool[n + 1];
            S = new List<int>[n + 1];
            for (int i = 1; i <= n; i++) S[i] = new List<int>();
            Console.WriteLine("Podaj krawędzie grafu, koniec zaznacz jako 0 0");
            int a = Convert.ToInt16(Console.ReadLine());
            int b = Convert.ToInt16(Console.ReadLine());
            while (a != 0)
            {
                S[a].Add(b); S[b].Add(a);
                a = Convert.ToInt16(Console.ReadLine());
                b = Convert.ToInt16(Console.ReadLine());
            }
        }
        public bool ma_zrodlo()
        {
            usun_zaznaczenia();
            DFS(1);
            for (int i = 1; i <= n; i++)
            {
                if (!zaznaczony(i)) return false;
            }
            return true;
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Graf G = new Graf();
            G.wczytaj_graf();
            if (G.ma_zrodlo())
            {
                Console.WriteLine("Graf posiada źródło w wierzchołku 1");
            }
            else
            {
                Console.WriteLine("Graf nie posiada źródła");
            }
            G.zaznacz(1);
            G.DFS(1);

            Console.WriteLine("   Koniec");
            Console.ReadLine();
        }
    }
}
