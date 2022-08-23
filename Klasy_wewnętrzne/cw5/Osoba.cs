using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace cw5
{
    class Osoba
    {
        public String nazwisko { get; set; }
        public String imie { get; set; }

        public void wypelnij_dane()
        {
            Console.WriteLine("To teraz będzie nam potrzebna Twoja tożsamość. "); 
            Console.Write("Proszę podaj swoję imię: ");
            imie = Console.ReadLine();
            Console.Write("Oraz nazwisko: ");
            nazwisko = Console.ReadLine();

        }

        private dane_osobowe uzup;

        public void wyciagnij()
        {
            uzup = new dane_osobowe(); 

            uzup.wypelinij_dane_priv();
            uzup.wyswietl_priv(); 
        }

        public void wyswietl_wszystko()
        {
            int wybor;

            Console.WriteLine("\r\nTo teraz pora na bardziej poufną część. \r\n"); 
            Console.WriteLine("Krótki opis znaczeniowy. "); 
            Console.WriteLine("1. Zameldowanie\r\n" +
                "2. Praca\r\n" +
                "3. Zamieszkanie\r\n" +
                "4. Uczelnia\r\n" +
                "5. Ulubione miejsce z jedzonkiem\r\n" +
                "6. Miejsce, które następne chcesz odwiedzić\r\n" +
                "7. Wyjście z programu ");


            do
            {
                Console.WriteLine("Jakie chcesz podać dane? ");
                wybor = int.Parse(Console.ReadLine());

                switch (wybor)
                {
                    case 7:
                        Console.WriteLine("No to wychodzimy :/ "); 
                        break;
                    case 1:
                        wyciagnij();
                        break;
                    case 2:
                        wyciagnij();
                        break;
                    case 3:
                        wyciagnij();
                        break;
                    case 4:
                        wyciagnij();
                        break;
                    case 5:
                        wyciagnij();
                        break;
                    case 6:
                        wyciagnij();
                        break;

                }

            }
            while (wybor != 7);

        }


        private class dane_osobowe
        {
            private string ulica { get; set; }
            private string  kod { get; set; }
            private string  miasto { get; set; }
            
            private int nr_ulicy { get; set; }
            private int nr_miesz { get; set; }  

            public void wypelinij_dane_priv()
            {
                Console.Write("Podaj ulicę: ");
                ulica = Console.ReadLine();
                Console.Write("Podaj kod: ");
                kod = Console.ReadLine();
                Console.Write("Podaj miasto: ");
                miasto = Console.ReadLine();

                Console.Write("Podaj numer ulicy: ");
                nr_ulicy = int.Parse(Console.ReadLine());
                Console.Write("Podaj numer mieszkania: ");
                nr_miesz = int.Parse(Console.ReadLine());

            }


            public void wyswietl_priv()
            {
                Console.WriteLine(); 
                Console.WriteLine("A oto dane już poufne. "); 
                Console.WriteLine("Ulica: " + ulica);
                Console.WriteLine("Kod: " + kod);
                Console.WriteLine("Miasto" + miasto );
                Console.WriteLine("Numer ulicy: " + nr_ulicy);
                Console.WriteLine("Numer mieszkania: " + nr_miesz);

            }



        }



    }
}
