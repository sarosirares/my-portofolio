#include <iostream>
#include "Sport.h"
#include "Active.h"

using namespace std;

void Active::set_AthleteName(string name)
{
	athleteName = name;
}
string Active::get_AthleteName()
{
	cout << "Method called by Active Class" << endl;
	return athleteName;
}

void Active::set_SportName(string name)
{
	sportName = name;
}
string Active::get_SportName()
{
	cout << "Method called by Active Class" << endl;
	return sportName;
}

void Active::set_CoachName(string name)
{
	coachName = name;
}
string Active::get_CoachName()
{
	cout << "Method called by Active Class" << endl;
	return coachName;
}

void Active::set_Wins(int numWin)
{
	wins = numWin;
}
int Active::get_Wins()
{
	cout << "Method called by Active Class" << endl;
	return wins;
}

void Active::set_MatchesPlayed(int matches)			//Lab3ex4
{
	matchesPlayed = matches;
}
int Active::get_MatchesPlayed()
{
	cout << "Method called by Active Class" << endl;
	return matchesPlayed;
}

void Active::set_Injuries(int inj)
{
	injuries = inj;;
}
int Active::get_Injuries()
{
	cout << "Method called by Active Class" << endl;
	return injuries;
}

void Active::set_fruit(string fruits)
{
	consume.fruit = fruits;
}
string Active::get_fruit()
{
	cout << "Method called by Active Class" << endl;
	return consume.fruit;
}

void Active::set_water(int wquantity)
{
	consume.water = wquantity;
}
int Active::get_water()
{
	cout << "Method called by Active Class" << endl;
	return consume.water;
}

void Active::Active_E_access()						//Lab3ex5
{
	cout << "Method called by Active Class" << endl;
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
