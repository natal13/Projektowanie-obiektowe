using System;
using System.Collections.Generic;
using System.Text;

namespace cw10
{
    class Osoba
    {
        public int Id;
        public string Imie;
        public string Nazwisko; 
        public int NrTelefonu;
        public int Wiek;

        public override string ToString()
        {
            
                return Id.ToString() + " " + Imie + " " + Nazwisko + " " + Wiek + " " + NrTelefonu; 
            
        }





    }
}
