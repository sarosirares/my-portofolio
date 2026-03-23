using System;
using System.CodeDom;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab5tema
{
    public class Sport : Activities
    {
        public int Age { set; get; }
        public string Country { set; get; }
        public string Athletename { set; get; }
        public string Sportname { set; get; }
        public string Coachname { set; get; }
        public int Wins { set; get; }
        public int Matchesplayed { set; get; }
        public int Injuries { set; get; }
        
        public Health_Diet Object = new Health_Diet();
 
        protected bool suspended;
        protected double height;

        //Lab5

        public void display_activity()
        {
            Console.WriteLine("The activity is: " + Sportname);
        }

        public void display_atname()
        {
            Console.WriteLine("The name is: " + Athletename);
        }

        public Sport()
        {
            
        }
    }
}
