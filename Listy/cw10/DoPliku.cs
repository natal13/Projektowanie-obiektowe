using System;
using System.Collections.Generic;
using System.Text;
using System.Xml.Linq;
using System.Linq; 

namespace cw10
{
    static class DoPliku
    {
        public static void ZapiszPlik(this IEnumerable<Osoba> osoby, string path)
        {
            XDocument xml = new XDocument(new XDeclaration("1.0", "utf-8", "yes"),
                new XElement("osoby", from osoba in osoby
                                      orderby osoba.Nazwisko, osoba.Imie
                                      select new XElement("osoba", new XAttribute("id", osoba.Id.ToString()),
                                      new XElement("imie",  osoba.Imie),
                                      new XElement("nazwisko", osoba.Nazwisko),
                                      new XElement("numerTelefonu", osoba.NrTelefonu.ToString()),
                                      new XElement("wiek", osoba.Wiek.ToString()))));
           
                
            xml.Save(path); 
        
        }
    }
}
