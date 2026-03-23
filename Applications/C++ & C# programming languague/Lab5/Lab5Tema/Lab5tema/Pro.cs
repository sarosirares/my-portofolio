using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab5tema
{
    public class Pro : Active
    {
        public string sponsor;
        public int earnings;

        public double get_earnings()
        {
            return earnings;
        }

        //Lab5
        public void display_years_activity()
        {
            Console.WriteLine("Display years of activity: " + years_activity + " (called by Pro Class)");
        }

        public override void display_suspended()
        {
            Console.WriteLine("Display days as suspended: " + suspended + " (called by Pro Class)");
        }
    }
}
