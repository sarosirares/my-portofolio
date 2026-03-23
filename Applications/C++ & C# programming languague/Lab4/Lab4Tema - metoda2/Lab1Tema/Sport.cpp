#include <iostream>
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

void Sport::set_fruit(string fruits)
{
	consume.fruit = fruits;
}
string Sport::get_fruit()
{
	return consume.fruit;
}

void Sport::set_water(int wquantity)
{
	consume.water = wquantity;
}
int Sport::get_water()
{
	return consume.water;
}

//cerinta 7
int Sport::contor = 0;

int Sport::get_contor()
{
	return contor;
}

//cerinta 8
string Sport::get_cerinta8() const
{
	return athleteName;
}

//Lab4ex3

void Sport::display_activity()
{
	cout << "The activity is: " << sportName << endl;
}

void Sport::display_atname()
{
	cout << "The athlete name is: " << athleteName << endl;
}


//implementare constructor implicit
Sport::Sport()
{
	athleteName = "Null";
	//sportName = "Null";
	coachName = "Null";
	wins = 0;
	matchesPlayed = 0;
	injuries = 0;
	cout << "Contstructor fara parametrii (implicit)" << endl;

	++contor;
}

//implementare constructori cerinta 1				//cerinta 6
Sport::Sport(int wins, int mp, int i)
{
	athleteName = "Null";
	sportName = "Null";
	coachName = "Null";
	this->wins = wins; //cerinta 6
	matchesPlayed = mp;
	injuries = i;
	cout << "Contstructor cu 3 parametrii int" << endl;

	++contor;
}
Sport::Sport(string n, string sn, string cn, int w)
{
	athleteName = n;
	sportName = sn;
	coachName = cn;
	wins = w;
	matchesPlayed = 0;
	injuries = 0;
	cout << "Contstructor cu 3 parametrii string si unul int" << endl;

	++contor;
}

//implementare constructor cerinta 4
Sport::Sport(string n, int w) : athleteName{ n }, wins{ w }
{
	cout << "Constructor cu lista de 2 parametrii" << endl;

	++contor;
}
Sport::Sport(string n) : athleteName{ n }
{
	cout << "Constructor cu lista de 1 parametru" << endl;

	++contor;
}

//implementare constructor cerinta 5
Sport::Sport(string n, string sn, string cn, int w, int mp, int i) : athleteName{ n }, sportName{ sn }, coachName{ cn }, wins{ w }, matchesPlayed{ mp }, injuries{ i }
{
	cout << "Constructor cu 6 parametrii" << endl;

	++contor;
}
Sport::Sport(string n, string sn, int w, int mp, int i) : Sport{ n, sn, "Null", w, mp, i }
{
	cout << "Constructor cu 5 parametrii (prin delegare)" << endl;
}

//implementare destructor (cerinta 3)
Sport::~Sport()
{
	cout << "Apelarea destructorului de catre: " << athleteName << endl;
	
	--contor;

	//cout << "Active players: " << Sport::get_contor() << endl << endl;
}