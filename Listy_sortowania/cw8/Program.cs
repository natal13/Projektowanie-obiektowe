using System;
using System.Collections.Generic; 

namespace cw8
{
    class Program
    {
        static void Main(string[] args)
        {
            // Console.WriteLine("Hello World!");

            /*
            int rozmiar;
            Random r = new Random();
            Console.WriteLine("Podaj rozmiar tablicy : ");
            rozmiar = int.Parse(Console.ReadLine());
            int[] tabliczka = new int[rozmiar]; //TABLICA MA STAŁY ROZMIAR 
            //jeżeli chcemy inny rozmiar to po prostu tworzymy inną teblicę 

            for(int i = 0; i< tabliczka.Length; i++)
            {
                tabliczka[i] = r.Next(100); 
            }

            foreach (int element in tabliczka)
                Console.WriteLine(element.ToString());

            int szukana = r.Next(100);
            Console.WriteLine("WArtość szukana : " + szukana);
            int index = Array.IndexOf(tabliczka, szukana);
            Console.WriteLine("Szukany indeks : " + index + "Szukana wartość to: "+tabliczka[index]); 


            //sortujemy 

            Array.Sort(tabliczka);

            // Console.WriteLine("Tablica po sortowaniu: "); 
            // foreach (int element in tabliczka)
            //    Console.WriteLine(element.ToString());

            int szukana2 = r.Next(100) ;
            int indeks = Array.BinarySearch(tabliczka, szukana2);


            Console.WriteLine("WArtość szukana : " + szukana2);
            Console.WriteLine("Szukany indeks : " + indeks + "Szukana (binarnie)  wartość to: " + tabliczka[indeks]);
            */



            /*
            //LISTY 

            int rozmiar = 10; 
            Random r = new Random();
            List<int> lista = new List<int>();

            //Console.WriteLine("Podaj ilość elementów listy : ");
            //int ilosc = int.Parse(Console.ReadLine()); 
            for(int i = 0; i<lista.Count; i++)
                lista.Add(1);

            lista.AddRange(new int[5]);

            int[] tab = new int[5]; 
            for (int i = 0; i < 5; i++)
                tab[i] = r.Next(100);

            lista.InsertRange(lista.Count / 2, tab);
            lista.Insert(1, -10);

            Console.WriteLine("Lista przed usuwaniem: ");

            foreach (object elementy in lista)
                Console.WriteLine(elementy);


            for (int i = 0; i<lista.Count; i++)
            {
                if(lista[i]<10)
                {
                    lista.RemoveAt(i);
                    i--; 
                }
            }
            lista.Sort(); 
            Console.WriteLine("Lista po usuwaniu: ");

            foreach (object elementy in lista)
                Console.WriteLine(elementy);
            */

            SortedList<string, string> ludzie = new SortedList<string, string>();
            ludzie.Add("Bolesław Prus", "Aleksander Głowacki");
            ludzie.Add("Bono", "Paul Newson");
            ludzie.Add("Chico", "Leonard Mars");
            ludzie.Add("Gabriela Zapolska", "Maria Gabriela Janowska");

            Console.WriteLine("Zawartość list ludzie:");
            foreach (KeyValuePair<string, string> osoba in ludzie)
                Console.WriteLine(osoba.Key + " " + osoba.Value + "\n"); 












        }
    }
}
