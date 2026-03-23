#include <iostream>
#include "Healthy_Diet.h"
using namespace std;

void Healthy_Diet::display_hydrated()				//Lab3ex3
{
	if (water < 2)
	{
		cout << "The athlete is not hydrated!" << endl;
	}
	else
	{
		cout << "The athlete is hydrated!" << endl;
	}
}