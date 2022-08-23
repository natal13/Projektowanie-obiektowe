using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace cw7
{
    class ParaMod<TOne, TTwo>
    {

        private TOne pierwszy = default(TOne);
        private TTwo drugi = default(TTwo);

        public ParaMod(TOne pierwszy, TTwo drugi)
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
