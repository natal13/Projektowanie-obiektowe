using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace cw7
{
    class Stos<T>
    {
        private Stos<T> obs = new Stos<T>();

        Func<T> getter;
        Action<T> setter; 
        
        public Stos (Func<T> g, Action<T> s)
        {
            getter = g;
            setter = s; 
        }

        public T Deref
        {
            get { return getter(); }
            set { setter(value); }
        }

        public static Stos<T> GetStos<T>(this T obj) => new Stos<T>(() => obj, v => obj = v);

        public void dodaj(T ob)
        {
            obs.dodaj(ob); 
        }






















        public T wloz()
        {
            if (obs.Count > 0)
            {
                T temp = obs[obs.Count - 1];
                obs.RemoveAt(obs.Count - 1);
                return temp;
            }
            else
                return default(T); 
        }

        public void usun (int pozyc) 
        {
            obs.RemoveAt(pozyc);
        }


    }
}


https://stackoverflow.com/questions/748387/how-to-remove-a-stack-item-which-is-not-on-the-top-of-the-stack-in-c-sharp


