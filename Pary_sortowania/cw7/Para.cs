using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace cw7
{
    class Para<T>//to jest szablon  typ 
    {
        private T pierwszy = default(T);
        private T drugi = default(T); 

        public Para (T pierwszy, T drugi)
        {
            this.pierwszy = pierwszy;
            this.drugi = drugi; 
        }

        public override string ToString()
        {
            return pierwszy.ToString() + "\t" + drugi.ToString(); 
        }


    }
}
