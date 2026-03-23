#include "Sport.h"
using namespace std;

//implementare metode

void Sport::set_AthleteName(string name)
{
	athleteName = name;
}
string Sport::get_AthleteName()
{
	return athleteName;
}

void Sport::set_SportName(string name)
{
	sportName = name;
}
string Sport::get_SportName()
{
	return sportName;
}

void Sport::set_CoachName(string name)
{
	coachName = name;
}
string Sport::get_CoachName()
{
	return coachName;
}

void Sport::set_Wins(int numWin)
{
	wins = numWin;
}
int Sport::get_Wins()
{
	return wins;
}

void Sport::set_MatchesPlayed(int matches)
{
	matchesPlayed = matches;
}
int Sport::get_MatchesPlayed()
{
	return matchesPlayed;
}

void Sport::set_Injuries(int inj)
{
	injuries = inj;;
}
int Sport::get_Injuries()
{
	return injuries;
}