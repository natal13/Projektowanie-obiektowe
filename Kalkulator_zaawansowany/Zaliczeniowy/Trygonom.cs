using System;
using System.Collections.Generic;
using System.Text;

namespace Zaliczeniowy
{
    class Trygonom
    {

        static private double sinus(double s)
        {
            s = Math.Sin(s);
            return s;
            
        }

        static private double cosinus(double c)
        {
            c = Math.Cos(c);

            return c;
        }

        static private double tangens(double t)
        {
            t = Math.Tan(t);

            return t;
        }

        static private double cotanges(double ct)
        {
            ct = 1/(Math.Tan(ct));

            return ct;
        }

        static private double asinus(double asi)
        {
            asi = Math.Asin(asi);

            return asi;
        }

        static private double acosinus(double aco)
        {
            aco = Math.Acos(aco);

            return aco;
        }

        static private double atangens(double ata)
        {
            ata = Math.Atan(ata);

            return ata;
        }

        static private double acotangens(double act)
        {
            act = 1/(Math.Atan(act));

            return act;
        }
    }
}
