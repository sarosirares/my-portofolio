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

	//Lab4

	void display_years_activity();		//Lab4ex1

	virtual void display_suspended() override;	//Lab4ex2
};

