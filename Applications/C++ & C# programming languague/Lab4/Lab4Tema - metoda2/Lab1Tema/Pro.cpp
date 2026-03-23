#include "Pro.h"
#include <iostream>

using namespace std;

double Pro::get_earnings()
{
	return earnings;
}

void Pro::Pro_E_access()			//Lab3ex5
{
	consume.display_hydrated();
}

//Lab4

void Pro::display_years_activity()
{
	cout << "Display years of activity: " << years_activity <<" (called by Pro Class)" << endl;		//Lab4ex1
}

void Pro::display_suspended()
{
	cout << "Display days as suspended: " << suspended << " (called by Pro Class)" << endl;		//Lab4ex2
}