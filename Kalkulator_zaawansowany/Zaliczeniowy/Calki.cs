using System;
using System.Collections.Generic;
using System.Text;

namespace Zaliczeniowy
{
    class Calki
    {

        public delegate double Calka(double x);

        private static double funkcja(double f)
        {
            //Console.Write("\nf= ");
            //double f = double.Parse(Console.ReadLine());
            return f;
        }


        //############## Metoda Prostokątów ###################

        private static double prostokatow(double a, double g, double h, Calka funkcja)
        {
           Console.WriteLine("To na początek podaj fukcję, którą będziemy całkować: ");
           Console.Write("\nf= ");
            double f = double.Parse(Console.ReadLine());
            funkcja(f);


           Console.WriteLine("To teraz podaj przedziały całkowania: ");
           Console.Write("\na - początek: ");
            a = double.Parse(Console.ReadLine());
           Console.Write("\ng - koniec: ");
            g = double.Parse(Console.ReadLine());

           Console.WriteLine("Podaj jeszcze krok, jaki funkcja będzie przemierzała przez algorytm\n" +
                "   (decyduje on o dokładności rozwiązania)\n");
           Console.Write("h: ");

            h = double.Parse(Console.ReadLine());

            double suma, wynik = 0;

            suma = (g - a) / h;

            for (int i = 1; i < h; i++)
            {
                wynik = wynik + funkcja(a + i * suma);
            }
            wynik = wynik * suma;

            return wynik;

        }

        //############## Metoda Trapezów  ###################


        private static double trapezow(double a, double g, double h, Calka funkcja)
        {
            Console.WriteLine("Pierwsze podaj całkowaną funkcję: ");
            Console.Write("\nf = ");
            double f = double.Parse(Console.ReadLine());
            funkcja(f);


            Console.WriteLine("To teraz podaj proszę przedziały całkowania: ");
            Console.Write("\na - początek: ");
            a = double.Parse(Console.ReadLine());
            Console.Write("\ng - koniec: ");
            g = double.Parse(Console.ReadLine());

            Console.WriteLine("Podaj jeszcze krok, jaki funkcja będzie przemierzała przez algorytm\n" +
                "   (decyduje on o dokładności rozwiązania)\n");
            Console.Write("h: ");

            h = double.Parse(Console.ReadLine());

            double suma, wynik = 0;

            suma = (g - a) / h;

            for(int i=1; i<h; i++)
            {
                wynik = wynik + funkcja(a + i * suma);
            }
            wynik = wynik + (funkcja(a) + funkcja(g)) / 2;
            wynik = wynik * suma;

            return wynik;
        }


        //############## Metoda Simpsona  ###################


        private static double simpsona(double a, double g, double h, Calka funkcja)
        {
            Console.WriteLine("Pierwsze podaj całkowaną funkcję: ");
            Console.Write("\nf = ");
            double f = double.Parse(Console.ReadLine());
            funkcja(f);


            Console.WriteLine("To teraz podaj proszę przedziały całkowania: ");
            Console.Write("\na - początek: ");
            a = double.Parse(Console.ReadLine());
            Console.Write("\ng - koniec: ");
            g = double.Parse(Console.ReadLine());

            Console.WriteLine("Podaj jeszcze krok, jaki funkcja będzie przemierzała przez algorytm\n" +
                "   (decyduje on o dokładności rozwiązania)\n");
            Console.Write("h: ");

            h = double.Parse(Console.ReadLine());

            double suma, wynik = 0;
            suma = (g - a) / h;
            double w = 0;
            double x = 0;
            for(int i = 1; i<h; i++)
            {
                x = a + i * suma;
                w = w + funkcja(x - suma / 2);
                wynik = wynik + funkcja(x);
            }
            w = w + funkcja(g - suma / 2);
            wynik = (suma / 6) * (funkcja(a) + funkcja(g) + 2 * wynik + 4 * suma);

            return wynik;
        }

    }
}
