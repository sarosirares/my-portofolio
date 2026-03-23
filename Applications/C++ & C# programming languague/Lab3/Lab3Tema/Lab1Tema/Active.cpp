#include <iostream>
#include "Sport.h"
#include "Active.h"

using namespace std;

void Active::set_MatchesPlayed(int matches)			//Lab3ex4
{
	matches -= suspended;
	Sport::set_MatchesPlayed(matches);
}

void Active::Active_E_access()						//Lab3ex5
{
	consume.display_hydrated();
}