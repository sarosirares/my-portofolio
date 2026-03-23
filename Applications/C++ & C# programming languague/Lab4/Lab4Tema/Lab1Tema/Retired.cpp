#include <iostream>
#include "Retired.h"

int Retired::get_retirement_year()
{
	cout << "Method called by Retired Class" << endl;
	return retirement_year;
}

void Retired::Retired_E_access()					//Lab3ex5
{
	cout << "Method called by Retired Class" << endl;
	consume.display_hydrated();
}

void Retired::set_AthleteName(string name)
{
	athleteName = name;
}
string Retired::get_AthleteName()
{
	cout << "Method called by Retired Class" << endl;
	return athleteName;
}

void Retired::set_SportName(string name)
{
	sportName = name;
}
string Retired::get_SportName()
{
	cout << "Method called by Retired Class" << endl;
	return sportName;
}

void Retired::set_CoachName(string name)
{
	coachName = name;
}
string Retired::get_CoachName()
{
	cout << "Method called by Retired Class" << endl;
	return coachName;
}

void Retired::set_Wins(int numWin)
{
	wins = numWin;
}
int Retired::get_Wins()
{
	cout << "Method called by Retired Class" << endl;
	return wins;
}

void Retired::set_MatchesPlayed(int matches)
{
	matchesPlayed = matches;
}
int Retired::get_MatchesPlayed()
{
	cout << "Method called by Retired Class" << endl;
	return matchesPlayed;
}

void Retired::set_Injuries(int inj)
{
	injuries = inj;;
}
int Retired::get_Injuries()
{
	cout << "Method called by Retired Class" << endl;
	return injuries;
}

void Retired::set_fruit(string fruits)
{
	consume.fruit = fruits;
}
string Retired::get_fruit()
{
	cout << "Method called by Retired Class" << endl;
	return consume.fruit;
}

void Retired::set_water(int wquantity)
{
	consume.water = wquantity;
}
int Retired::get_water()
{
	cout << "Method called by Retired Class" << endl;
	return consume.water;
}