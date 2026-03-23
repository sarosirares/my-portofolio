#include "Pro.h"
#include <iostream>

using namespace std;

void Pro::set_AthleteName(string name)
{
	athleteName = name;
}
string Pro::get_AthleteName()
{
	cout << "Method called by Pro Class" << endl;
	return athleteName;
}

void Pro::set_SportName(string name)
{
	sportName = name;
}
string Pro::get_SportName()
{
	cout << "Method called by Pro Class" << endl;
	return sportName;
}

void Pro::set_CoachName(string name)
{
	coachName = name;
}
string Pro::get_CoachName()
{
	cout << "Method called by Pro Class" << endl;
	return coachName;
}

void Pro::set_Wins(int numWin)
{
	wins = numWin;
}
int Pro::get_Wins()
{
	cout << "Method called by Pro Class" << endl;
	return wins;
}

void Pro::set_MatchesPlayed(int matches)
{
	matchesPlayed = matches;
}
int Pro::get_MatchesPlayed()
{
	cout << "Method called by Pro Class" << endl;
	return matchesPlayed;
}

void Pro::set_Injuries(int inj)
{
	injuries = inj;;
}
int Pro::get_Injuries()
{
	cout << "Method called by Pro Class" << endl;
	return injuries;
}

void Pro::set_fruit(string fruits)
{
	consume.fruit = fruits;
}
string Pro::get_fruit()
{
	cout << "Method called by Pro Class" << endl;
	return consume.fruit;
}

void Pro::set_water(int wquantity)
{
	consume.water = wquantity;
}
int Pro::get_water()
{
	cout << "Method called by Pro Class" << endl;
	return consume.water;
}


double Pro::get_earnings()
{
	return earnings;
}

void Pro::Pro_E_access()			//Lab3ex5
{
	cout << "Method called by Pro Class" << endl;
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

