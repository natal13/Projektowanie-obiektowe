using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace cw5
{
    class Program
    {
        /*delegate int Delegacja(int aa, int bb);
        delegate void Pokaz_inc(int nn);

        static int Dodawanie(int pierwszy, int drugi)
        {
            return pierwszy + drugi; 
        }

        static void Pokaz_wieksza(int liczba)
        {
            Console.WriteLine("Wartość zwiększona o 1: " + (liczba + 1)); 
        }*/


        static void Main(string[] args)
        {


            Console.WriteLine("Dzień dobry. Oto program testujący klasy wewnętrzne. ");

            Osoba czlowiek = new Osoba();
            czlowiek.wypelnij_dane(); 
            czlowiek.wyswietl_wszystko(); 

            Console.ReadKey();



            /*

            
            /*int aa, bb;

            Delegacja Dodaj = Dodawanie;
            Pokaz_inc Zwieksz = Pokaz_wieksza; 

            Console.WriteLine("Podaj pierwszą i drugą wartość: ");
            aa = int.Parse(Console.ReadLine()); 
            bb = int.Parse(Console.ReadLine());


            Console.WriteLine("Wynik dodawania to: " + Dodaj(aa, bb));
            Zwieksz(aa);

            // lambda jakaś w delegatach (parametry) => wartość; 


            Delegacja Sumuj = (int pierwsza, int druga) =>
            {
                return pierwsza + druga;
            };








            //a to całościowo są klasy wewnętrzne 
            NowaW pierwszy;
            pierwszy = new NowaW();
            pierwszy.test_klasy_wew();

            //NowaW.Wew.ob;
            //object = new NowaW.Wew.();
            //object.wypelnij();
            */



            
        }
    }
}
