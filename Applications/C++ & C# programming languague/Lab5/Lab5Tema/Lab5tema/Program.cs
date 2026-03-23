using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab5tema
{
    internal class Program
    {
        static void Main(string[] args)
        {
            //Lab5

            var Mihai = new Active
            {
                Athletename = "Mihai",
                years_activity = 8,
                suspended = 4
            };

            var Edi = new Pro
            {
                Athletename = "Edi",
                years_activity = 17,
                suspended = 67
            };

            var div = new List<Active>();   //for dynamic binding
            div.Add(new Active()
            {
                years_activity = 20,
                suspended = 5
            });
            div.Add(new Pro()
            {
                years_activity = 10,
                suspended = 1
            });

            //Lab5ex1

            Console.WriteLine(" === Static Binding === \n");
            Mihai.display_years_activity();
            Edi.display_years_activity();
            foreach(var active in div)
            {
                active.display_years_activity();
            }

            //Lab5ex2

            Console.WriteLine("\n === Dynamic Binding === \n");
            Mihai.display_suspended();
            Edi.display_suspended();
            foreach (var active in div)
            {
                active.display_suspended();
            }

            //Lab5ex3

            var Gabriel = new Sport
            {
                Sportname = "Tenis",
                Athletename = "Gabriel"
            };

            Console.WriteLine("\n === Interface === \n");
            Gabriel.display_atname();
            Gabriel.display_activity();

            Console.WriteLine("\n");

        }
    }
}
