using System;
using System.Collections.Generic;
using System.Text;

namespace Zaliczeniowy
{
    struct Ulamek
    {
        private double licznik { get; set; }
        private double mianownik { get; set; }

        public double L => licznik;
        public double M => mianownik;

        public Ulamek(double l, double m)
        {

            licznik = l;
            mianownik = m;
        }


        public void Uprosc()
        {
            double a = licznik;
            double b = mianownik;
            //NWD
            double c;
            while (b != 0)
            {
                c = a % b;
                a = b;
                b = c;
            }
            licznik /= a;
            mianownik /= a;
            //znaki
            if (licznik * mianownik < 0)
            {
                licznik = -Math.Abs(licznik);
                mianownik = Math.Abs(mianownik);
            }
            else
            {
                licznik = Math.Abs(licznik);
                mianownik = Math.Abs(mianownik);
            }
        }



        //operatory arytmetyczne

        public static Ulamek operator +(Ulamek u1)
        {
            Ulamek wynik = u1;
            return wynik;
        }

        public static Ulamek operator -(Ulamek u1)
        {
            Ulamek wynik = new Ulamek(-1 * u1.licznik, u1.mianownik);
            return wynik;
        }

        public static Ulamek operator +(Ulamek u1, Ulamek u2)
        {
            Ulamek wynik = new Ulamek(
            u1.licznik * u2.mianownik + u2.licznik * u1.mianownik,
            u1.mianownik * u2.mianownik);
            //wynik.Uprosc();
            return wynik;
        }

        public static Ulamek operator ++(Ulamek u1)
        {
            Ulamek wynik = new Ulamek(u1.licznik + u1.mianownik, u1.mianownik);
            //wynik.Uprosc();
            return wynik;
        }

        public static Ulamek operator --(Ulamek u1)
        {
            Ulamek wynik = new Ulamek(u1.licznik - u1.mianownik, u1.mianownik);
            //wynik.Uprosc();
            return wynik;
        }

        public static Ulamek operator -(Ulamek u1, Ulamek u2)
        {
            Ulamek wynik = new Ulamek(
            u1.licznik * u2.mianownik - u2.licznik * u1.mianownik,
            u1.mianownik * u2.mianownik);
            //wynik.Uprosc();
            return wynik;
        }

        public static Ulamek operator *(Ulamek u1, Ulamek u2)
        {
            Ulamek wynik = new Ulamek(
            u1.licznik * u2.licznik, u1.mianownik * u2.mianownik);
            // wynik.Uprosc();
            return wynik;
        }

        public static Ulamek operator /(Ulamek u1, Ulamek u2)
        {
            Ulamek wynik = new Ulamek(
            u1.licznik * u2.mianownik, u1.licznik * u2.mianownik);
            // wynik.Uprosc();
            return wynik;
        }

        public static Ulamek Pierwiastek(Ulamek u1)
        {
            Ulamek wynik = new Ulamek(Math.Sqrt(u1.licznik), Math.Sqrt(u1.mianownik)); 

            return wynik;
        }


        /*

        public override bool Equals(object obj)
        {
            return obj is Ulamek u1 && this.L == u1.L && this.M == u1.M;
        }

        public override int GetHashCode()
        {
            return (L, M).GetHashCode();
        }





        //operatory porównania
        public static bool operator ==(Ulamek u1, Ulamek u2)
        {
            u1.Uprosc();
            u2.Uprosc();
            return u1.licznik == u2.licznik && u1.mianownik == u2.mianownik;

        }


        public static bool operator !=(Ulamek u1, Ulamek u2)
        {
            u1.Uprosc();
            u2.Uprosc();
            return u1.licznik != u2.licznik || u1.mianownik != u2.mianownik;
        }



        public static bool operator >(Ulamek u1, Ulamek u2)
        {
            Ulamek U1 = new Ulamek(
           u1.licznik * u2.licznik + u1.licznik, u1.mianownik * u2.mianownik);

            Ulamek U2 = new Ulamek(
           u2.licznik * u1.licznik + u2.licznik, u1.mianownik * u2.mianownik);

            return U1.licznik > U2.licznik;
        }

        public static bool operator >=(Ulamek u1, Ulamek u2)
        {
            Ulamek U1 = new Ulamek(
            u1.licznik * u2.licznik + u1.licznik, u1.mianownik * u2.mianownik);

            Ulamek U2 = new Ulamek(
            u2.licznik * u1.licznik + u2.licznik, u1.mianownik * u2.mianownik);

            return U1.licznik >= U2.licznik;
        }

        public static bool operator <(Ulamek u1, Ulamek u2)
        {
            Ulamek U1 = new Ulamek(
            u1.licznik * u2.licznik + u1.licznik, u1.mianownik * u2.mianownik);

            Ulamek U2 = new Ulamek(
            u2.licznik * u1.licznik + u2.licznik, u1.mianownik * u2.mianownik);

            return U1.licznik < U2.licznik;
        }

        public static bool operator <=(Ulamek u1, Ulamek u2)
        {
            Ulamek U1 = new Ulamek(
            u1.licznik * u2.licznik + u1.licznik, u1.mianownik * u2.mianownik);

            Ulamek U2 = new Ulamek(
            u2.licznik * u1.licznik + u2.licznik, u1.mianownik * u2.mianownik);

            return U1.licznik <= U2.licznik;
        }
        */
    }

}
