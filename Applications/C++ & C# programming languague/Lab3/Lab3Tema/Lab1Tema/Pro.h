#pragma once

#include "Active.h"
#include <string>

using namespace std;

class Pro : public Active
{
public:
	string sponsor;
	int earnings;

	double get_earnings();

	void Pro_E_access();				//Lab3ex5
};

