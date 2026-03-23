using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab5tema
{
    public class Retired : Sport
    {
        public int retirement_year;
        public string motive;

        public int get_retirement_year()
        {
            return retirement_year;
        }
    }
}
