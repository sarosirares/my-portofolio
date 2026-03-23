#include <iostream>
#include "Sport.h"
#include "Active.h"

using namespace std;

void Active::set_MatchesPlayed(int matches)			//Lab3ex4
{
	matches -= suspended;
	Sport::set_MatchesPlayed(matches);
}

void Active::Active_E_access()						//Lab3ex5
{
	consume.display_hydrated();
}

//Lab4

void Active::display_years_activity()
{
	cout << "Display years of activity: "<< years_activity << " (called by Active Class)" << endl;		//Lab4ex1
}

void Active::display_suspended()
{
	cout << "Display days as suspended: " << suspended << " (called by Active Class)" << endl;		//Lab4ex2
}