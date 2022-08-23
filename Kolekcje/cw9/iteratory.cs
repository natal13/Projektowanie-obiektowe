using System;
using System.Collections.Generic;
using System.Text;

namespace cw9
{
    class iteratory
    {

        public uint zliczaj_elementy<T>(IEnumerable<T> kolekcja)
        {
            uint liczba = 0;
            IEnumerator<T> iterator = kolekcja.GetEnumerator(); 
            while (iterator.MoveNext())
            {
                liczba++; 
            }
            return liczba; 
        }

        public void pokaz<T>(IEnumerable<T> kolekcja)
        {
            IEnumerator<T> iterator = kolekcja.GetEnumerator();
            while (iterator.MoveNext())
            {
                T element = iterator.Current;
                Console.WriteLine(element.ToString()); 
            }
        }

        public T pobierz_element<T>(IEnumerable<T> kolekcja, int index)
        {
            IEnumerator<T> iterator = kolekcja.GetEnumerator();
            int indeks = 0; 
            while(iterator.MoveNext())
            {
                if (iterator.MoveNext())
                    return iterator.Current;
                indeks++; 
            }
            throw new IndexOutOfRangeException("Wyjątek"); 

        }


    }
}
