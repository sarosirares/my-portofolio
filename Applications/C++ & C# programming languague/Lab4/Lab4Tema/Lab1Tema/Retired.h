#pragma once

#include "Sport.h"
#include <string>

using namespace std;

class Retired : public Sport
{
public:
	
	//Lab4ex3 - The implementation of the methods from the interface
	virtual void set_AthleteName(string name) override;
	virtual string get_AthleteName() override;

	virtual void set_SportName(string name) override;
	virtual string get_SportName() override;

	virtual void set_CoachName(string name) override;
	virtual string get_CoachName() override;

	virtual void set_Wins(int numWin) override;
	virtual int get_Wins() override;

	virtual void set_MatchesPlayed(int matches) override;
	virtual int get_MatchesPlayed() override;

	virtual void set_Injuries(int inj) override;
	virtual int get_Injuries() override;

	virtual void set_fruit(string fruits) override;
	virtual string get_fruit();

	virtual void set_water(int wquantity) override;
	virtual int get_water() override;

	int retirement_year;
	string motive;

	int get_retirement_year();

	void Retired_E_access();			//Lab3ex5
};

