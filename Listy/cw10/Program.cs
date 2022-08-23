using System;
using System.Linq;
using System.Collections.Generic;

namespace cw10
{
    class Program
    {
        static List<Osoba> ListaOsob = new List<Osoba>
        {
            new Osoba {Id=1, Imie ="Anatol", Nazwisko = "Kaszub", NrTelefonu =12345677, Wiek = 27 },
            new Osoba {Id=2, Imie ="Adam", Nazwisko = "Krzyszkowski", NrTelefonu =12465727, Wiek = 23 },
            new Osoba {Id=3, Imie ="Maciej", Nazwisko = "Kowalczyk", NrTelefonu =11175477, Wiek = 21 },
            new Osoba {Id=4, Imie ="Julia", Nazwisko = "Pioro", NrTelefonu =346132597, Wiek = 17 },
            new Osoba {Id=5, Imie ="Dawid", Nazwisko = "Polak", NrTelefonu =101976377, Wiek = 24 },
            new Osoba {Id=6, Imie ="Justyna", Nazwisko = "Paluch", NrTelefonu =176546377, Wiek = 28 },
        }; 

        static void Main(string[] args)
        {
            //   Console.WriteLine("Hello World!");

            //operatory linkowe z baz danych 
            var Lista_Doroslych = from osoba in ListaOsob
                                 where osoba.Wiek >= 18
                                 orderby osoba.Wiek
                                 select osoba;
            Console.WriteLine("Lista osób pełnoletnich: ");
            foreach (var osoba in Lista_Doroslych)
                Console.WriteLine(osoba.ToString());


            List<Osoba> Lista_po_zapytaniu = Lista_Doroslych.ToList<Osoba>();
            Console.WriteLine("Osoba najstarsza to:" + Lista_Doroslych.Max(osoba => osoba.Wiek));
            Console.WriteLine();
            Console.WriteLine("Średnie wiek wśród osób dorosłych: " + Lista_Doroslych.Average(osoba => osoba.Wiek));
            Console.WriteLine();
            Console.WriteLine("Suma wieku wszystkich doroslych to: " + Lista_Doroslych.Sum(osoba => osoba.Wiek));
            Console.WriteLine();

            bool czyPelnoletnia = Lista_Doroslych.All(osoba => osoba.Wiek > 18);

            Osoba pierwsza = Lista_Doroslych.First<Osoba>();
            Console.WriteLine(pierwsza.ToString());

            pierwsza.Imie = "Adrian";
            Console.WriteLine(pierwsza.ToString());


            var GrupowanieNazwiskami = from osoba in ListaOsob
                                       group osoba by osoba.Nazwisko into grupa
                                       select grupa;

            Console.WriteLine("Grupy z tym samym nazwiskiem:"); 
            foreach(var grupa in GrupowanieNazwiskami)
            {
                Console.WriteLine("Osoby o nazisku " + grupa.Key);
                foreach (Osoba osoba in grupa)
                    Console.WriteLine(osoba.Imie + " " + osoba.Nazwisko);
                Console.WriteLine(); 
            }

            Console.WriteLine();

            var ListaNazwisk = from osoba in ListaOsob
                               select new { osoba.Id, osoba.Imie, osoba.Nazwisko };

            var ListaTel = from osoba in ListaOsob
                           select new { osoba.Id, osoba.NrTelefonu };

            foreach (var telefony in ListaTel)
                Console.WriteLine(telefony.ToString());
            Console.WriteLine(); 

            var ListaNazwiskTelefony = from telefony in ListaTel
                                       join
                                       nazwiska in ListaNazwisk
                                       on telefony.Id equals nazwiska.Id
                                       select new { telefony.Id, nazwiska.Imie, nazwiska.Nazwisko, telefony.NrTelefonu };

            foreach (var osoba in ListaNazwiskTelefony)
                Console.WriteLine(osoba.ToString());


            ListaOsob.ZapiszPlik("C:/osoby.xml"); 




        }
    }
}
