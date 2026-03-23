#pragma once
#include <string>
using namespace std;

class Sport {
private:
	//definire atribute
	string athleteName;
	string sportName;
	string coachName;
	int wins;
	int matchesPlayed;
	int injuries;
public:
	//definire metode
	void set_AthleteName(string name);
	string get_AthleteName();

	void set_SportName(string name);
	string get_SportName();

	void set_CoachName(string name);
	string get_CoachName();

	void set_Wins(int numWin);
	int get_Wins();

	void set_MatchesPlayed(int matches);
	int get_MatchesPlayed();

	void set_Injuries(int inj);
	int get_Injuries();
};

