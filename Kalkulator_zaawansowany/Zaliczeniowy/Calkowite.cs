using System;
using System.Collections.Generic;
using System.Text;

namespace Zaliczeniowy
{
    class Calkowite
    {
        private int w;
        private double liczba1 { get; set; }
        private double liczba2 { get; set; }

        public double L1 => liczba1;
        public double L2 => liczba2;

        public Calkowite(double licz1, double licz2)
        {

            liczba1 = licz1;
            liczba2 = licz2;
        }

        public Calkowite(int w)
        {
            this.w = w;
        }

        public static Calkowite operator - (Calkowite r1)
        {
            r1.liczba1 = -r1.liczba1;
            r1.liczba2 = -r1.liczba2;
            return r1; 
        }

        public static Calkowite operator +(Calkowite r1, Calkowite r2)
        {
            Calkowite wynik = new Calkowite(0);
            wynik.w = r1.w + r2.w;
            return wynik;

        }

        public static Calkowite operator -(Calkowite r1, Calkowite r2)
        {
            Calkowite wynik = new Calkowite(0);
            wynik.w = r1.w - r2.w;
            return wynik; 
        }

        public static Calkowite operator *(Calkowite r1, Calkowite r2)
        {
            Calkowite wynik = new Calkowite(0);
            wynik.w = r1.w * r2.w;
            return wynik;
        }

        public static Calkowite operator /(Calkowite r1, Calkowite r2)
        {
            Calkowite wynik = new Calkowite(0);

            if ((r2.w != 0 & r2.w != 0) || r2.w !=0)//
            {
                wynik.w = r1.w / r2.w;
                return wynik;
            }
            else
            {
               Console.WriteLine("Nie można dzielić przez 0!");
                wynik = null; 
                return wynik ;
            }

        }

        public static Calkowite operator ^(Calkowite r1, Calkowite r2)
        {
            Calkowite wynik = new Calkowite(0);
            wynik.liczba1 = Math.Pow(r1.liczba1, r2.liczba1);
            wynik.liczba2 = Math.Pow(r1.liczba2, r2.liczba2);

            return wynik;
        }


        public static Calkowite Pierwiastek(Calkowite r1)
        {
            Calkowite wynik = new Calkowite(0);
            return wynik;
        }

        public static int Bezgledna(int r1)
        {
            if (r1 >= 0)
                return r1;
            else
                return -r1;
        }
        public void view()
        {
            Console.WriteLine("Wynik działania to: " + w);

        }

    }
}
