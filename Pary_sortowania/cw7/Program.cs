using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace cw7
{
    class Program
    {
        static void Main(string[] args)
        {
            


            Random r = new Random(); 

            Para<int>[] para_tab = new Para<int>[10]; 

            for (int i = 0; i< para_tab.Length; i++)
            {
                para_tab[i] = new Para<int>(r.Next(10), r.Next(10));
              

            }
            Console.WriteLine("Para<int>: ");
            foreach (Para<int> parka in para_tab)
                Console.WriteLine(parka.ToString());




            Para<double>[] para_tab_d = new Para<double>[10];

            for (int i = 0; i < para_tab_d.Length; i++)
            {
                para_tab_d[i] = new Para<double>(r.Next(10), r.Next(10));
            }
            Console.WriteLine("Para<double>: ");
            foreach (Para<double> parka in para_tab_d)
                Console.WriteLine(parka.ToString());


            NowaPara<int>[] paran_n = new NowaPara<int>[10];
            for (int i = 0; i < paran_n.Length; i++)
                paran_n[i] = new NowaPara<int>(r.Next(10), r.Next(10));
            Console.WriteLine("NowaPara<int>: ");

            foreach (NowaPara<int> para in paran_n)
                Console.WriteLine(para.ToString());

            Console.WriteLine("NowaPara<int> po sortowaniu: ");
            Array.Sort(paran_n);
            foreach (NowaPara<int> para in paran_n)
                Console.WriteLine(para.ToString());






        }
    }
}
