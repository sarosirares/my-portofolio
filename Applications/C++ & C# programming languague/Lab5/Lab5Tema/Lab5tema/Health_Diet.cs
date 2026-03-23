using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab5tema
{
    public class Health_Diet
    {
        public string Fruit { set; get; }
        public int Water { set; get; }

        public void display_hydrated()
        {
            if (Water < 2)
            {
                Console.WriteLine("The athlete is not hydrated!");
            }
            else
            {
                Console.WriteLine("The athlete is hydrated!");
            }
        }
    }
}
