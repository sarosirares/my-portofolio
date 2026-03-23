using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;

namespace Lab5tema
{
    public class Active : Sport
    {
        public int years_activity;
        public int suspended;
        public void set_MatchesPlayed(int matches)
        {
            matches -= suspended;
        }

        //Lab5
        public void display_years_activity()
        {
            Console.WriteLine("Display years of activity: " + years_activity + " (called by Active Class)");
        }

        public virtual void display_suspended()
        {
            Console.WriteLine("Display days as suspended: " + suspended + " (called by Active Class)");
        }
    }
}
