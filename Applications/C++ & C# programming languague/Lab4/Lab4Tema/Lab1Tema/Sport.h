#pragma once

#include "Healthy_Diet.h"
#include <string>

using namespace std;

class Sport {
public:				//Lab3ex2

	int age;
	string country;

protected:

	string athleteName;
	string sportName;
	string coachName;
	int wins;
	int matchesPlayed;
	int injuries;

	bool suspended;
	double height;

	Healthy_Diet consume; //Lab3ex3

public:

	//definire metode
	virtual void set_AthleteName(string name) = 0;
	virtual string get_AthleteName() = 0;

	virtual void set_SportName(string name) = 0;
	virtual string get_SportName() = 0;

	virtual void set_CoachName(string name) = 0;
	virtual string get_CoachName() = 0;

	virtual void set_Wins(int numWin) = 0;
	virtual int get_Wins() = 0;

	virtual void set_MatchesPlayed(int matches) = 0;
	virtual int get_MatchesPlayed() = 0;

	virtual void set_Injuries(int inj) = 0;
	virtual int get_Injuries() = 0;

	virtual void set_fruit(string fruits) = 0;
	virtual string get_fruit() = 0;

	virtual void set_water(int wquantity) = 0;
	virtual int get_water() = 0;


	//definire constructor implicit
	//Sport();
	
	/*
	//definire constructori cerinta 1				//cerinta 6
	Sport(int wins, int mp, int i);					//cerinta 6
	Sport(string n, string sn, string cn, int w);

	//definire constructori cerinta 4
	Sport(string n, int w);
	Sport(string n);

	//definire cerinta 5
	Sport(string n, string sn, string cn, int w, int mp, int i);
	Sport(string n, string sn, int w, int mp, int i);
	*/

	//definire destructor (cerinta 3)
	//virtual ~Sport();
};