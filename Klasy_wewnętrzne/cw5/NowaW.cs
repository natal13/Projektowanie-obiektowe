using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace cw5
{
    
    class NowaW
    {
        private string nazwa;
        private int id;
        private Wew obiekcik; //to jest wazne

        public string Nazwa { get; set;  }
        public int ID { get; set;  }
        //public void test_klasy_wew()

        public void test_klasy_wew()
        {
            obiekcik = new Wew();
            obiekcik.wypelnij(); 
        }

        public class Wew
        {
            private long pierwsza;
            private string druga_nazwa; 

            public void wypelnij()
            {
                Console.WriteLine("Podaj nazwę: ");
                druga_nazwa = Console.ReadLine();
                Console.WriteLine("Podaj liczbę: ");
                pierwsza = long.Parse(Console.ReadLine()); 

            }

            public Wew()
            {
                Console.WriteLine("Klasa wewnętrzna"); 

            }

        }


    }
}
