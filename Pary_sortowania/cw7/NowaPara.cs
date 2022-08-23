using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace cw7
{
    class NowaPara<T>: 
        IComparable<NowaPara<T>>
        where T:IComparable<T>
    {
        private T pierwszy = default(T);
        private T drugi = default(T);

        public NowaPara(T pierwszy, T drugi)
        {
            this.pierwszy = pierwszy;
            this.drugi = drugi;
        }

        public override string ToString()
        {
            return pierwszy.ToString() + "\t" + drugi.ToString();
        }


        public int CompareTo(NowaPara<T> InnaPara)
        {
            int wartosc = this.pierwszy.CompareTo(InnaPara.pierwszy);
            if (wartosc != 0)
                return wartosc;
            else
                return this.drugi.CompareTo(InnaPara.pierwszy); 
        }







    }
}
