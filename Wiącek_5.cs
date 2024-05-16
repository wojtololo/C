using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Lab5
{
    class Queue
    {
        public List<int> L;
        public Archiwum A;
        string nazwaObiektu;
        public int front() { A.register(new KeyValuePair<string, string>(nazwaObiektu, "front()")); return L[0]; }
        public int end() { A.register(new KeyValuePair<string, string>(nazwaObiektu, "end()")); return L[L.Count() - 1]; }
        public void dequeue() { A.register(new KeyValuePair<string, string>(nazwaObiektu, "dequeue()")); L.Remove(L[0]); }
        public void enqueue(int a)
        {
            string s = "enqueue(" + Convert.ToString(a) + ")";
            A.register(new KeyValuePair<string, string>(nazwaObiektu, s));
            L.Add(a);

        }
        public bool empty() { A.register(new KeyValuePair<string, string>(nazwaObiektu ,"empty()")); return L.Count() == 0; }
        public void make_empty() { A.register(new KeyValuePair<string, string>(nazwaObiektu, "make_empty()")); L.Clear(); }
        public int card() { A.register(new KeyValuePair<string, string>(nazwaObiektu, "card()")); return L.Count(); }
        public void show() { A.register(new KeyValuePair<string, string>(nazwaObiektu, "show()")); foreach (int x in L) Console.Write(x + " "); Console.WriteLine(); }
        public Queue(Archiwum archiwum, string nazwaObiektu) { 
            L = new List<int>(); 
            A = archiwum;
            this.nazwaObiektu = nazwaObiektu;
        }
    }
    class Archiwum
    {
        public List<KeyValuePair<string, string>> L;
        public void register(KeyValuePair<string, string> para)
        { 
            L.Add(para); 
        }
        public void historia(string id) {
            foreach (KeyValuePair<string, string> para in L)
            {   
                if(para.Key == id)
                {
                    Console.WriteLine(para.Value);
                }
                
            }
        }

        public Archiwum() { L = new List<KeyValuePair<string, string>>(); }
    }
    class Program
    {
        static void Main(string[] args)
        {

            Archiwum historia = new Archiwum();
            Queue Q1 = new Queue(historia, "Q1");
            Queue Q2 = new Queue(historia, "Q2");
            Q1.enqueue(1);
            Q1.enqueue(2);
            Q1.enqueue(3);
            Q1.enqueue(4);
            Q1.enqueue(5);

            Q2.enqueue(3);
            Q2.enqueue(4);
            Q2.enqueue(5);

            Q1.show();

            Q1.dequeue();
            Q1.dequeue();
            
            Q2.dequeue();
            Q1.show();

            Console.WriteLine("czy Q1 pusta?" + Q1.empty());

            Q1.make_empty();
            Console.WriteLine("czy Q1 pusta" + Q1.empty());
            Q1.show();

            historia.historia("Q1");
        }
    }
}
