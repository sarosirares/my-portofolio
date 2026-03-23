#pragma once

#include "Sport.h"
#include <string>

using namespace std;

class Active : public Sport
{
public:
	int years_activity;
	int suspended;

protected:
	string team;

public:
	void set_MatchesPlayed(int matches);		//Lab3ex4

	void Active_E_access();						//Lab3ex5
};

