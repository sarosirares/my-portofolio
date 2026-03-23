#pragma once

#include "Sport.h"
#include <string>

using namespace std;

class Retired : public Sport
{
public:
	int retirement_year;
	string motive;

	int get_retirement_year();

	void Retired_E_access();			//Lab3ex5
};

