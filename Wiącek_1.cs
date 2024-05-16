using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace lab1
{
    class Ulamek
    {
        public int l;
        public int m;

        public void pokaz()
        {
            Console.WriteLine(l + "/" + m);
        }
        public Ulamek(int a, int b)
        {
            if (b != 0)
            {
                l = a;
                m = b;
            }
            else
            {
                l = 0;
                m = 1;
            }
        }
    }
    class Arytmetyka_Ulamkow
    {
        public Ulamek dod(Ulamek u1, Ulamek u2)
        {
            int a = u1.l * u2.m + u2.l * u1.m;
            int b = u1.m * u2.m;
            Ulamek u = new Ulamek(a, b);
            return u;
        }
        public Ulamek odj(Ulamek u1, Ulamek u2)
        {
            int a = u1.l * u2.m - u2.l * u1.m;
            int b = u1.m * u2.m;
            Ulamek u = new Ulamek(a, b);
            return u;
        }
        public Ulamek mnz(Ulamek u1, Ulamek u2)
        {
            int a = u1.l * u2.l;
            int b = u1.m * u2.m;
            Ulamek u = new Ulamek(a, b);
            return u;
        }
        public Ulamek dzl(Ulamek u1, Ulamek u2)
        {
            int a = u1.l * u2.m;
            int b = u1.m * u2.l;
            Ulamek u = new Ulamek(a, b);
            return u;
        }
        public Ulamek skr(Ulamek u)
        {
            int p = nwd(Math.Abs(u.l), Math.Abs(u.m));
            int a = u.l / p;
            int b = u.m / p;
            return new Ulamek(a, b);
        }
        private int nwd(int a, int b)
        {
            if (b != 0)
            {
                return nwd(b, a % b);
            }
            return a;
        }


    }
    class Program
    {
        static void Main(string[] args)
        {
            Arytmetyka_Ulamkow A = new Arytmetyka_Ulamkow();
            Ulamek u1 = new Ulamek(2, 3);
            Ulamek u2 = new Ulamek(3, 2);
            Ulamek u3 = A.dod(u1, u2);
            Ulamek u4 = new Ulamek(4, 6);
            Ulamek u5 = new Ulamek(1, 2);
            Ulamek u6 = A.odj(u4, u5);
            Ulamek u7 = A.mnz(u3, u6);
            Ulamek u8 = new Ulamek(2, 8);
            Ulamek u9 = A.dod(u7, u8);
            Ulamek u10 = new Ulamek(1, 2);
            Ulamek u11 = new Ulamek(3, 5);
            Ulamek u12 = A.dod(u10, u11);
            Ulamek wynik = A.dzl(u9, u12);
            A.skr(wynik).pokaz();

        }
    }
}
