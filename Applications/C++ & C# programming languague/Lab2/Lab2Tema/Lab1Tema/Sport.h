#pragma once
#include <string>
using namespace std;

class Sport {
private:
	static int contor;			//cerinta 7

	//definire atribute
	string athleteName;
	string sportName;
	string coachName;
	int wins;
	int matchesPlayed;
	int injuries;

public:
	static int get_contor();		//cerinta 7

	string get_cerinta8() const;	//cerinta 8 

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

	//definire constructor implicit
	Sport();

	//definire constructori cerinta 1				//cerinta 6
	Sport(int wins, int mp, int i);					//cerinta 6
	Sport(string n, string sn, string cn, int w);

	//definire constructori cerinta 4
	Sport(string n, int w);
	Sport(string n);

	//definire cerinta 5
	Sport(string n, string sn, string cn, int w, int mp, int i);
	Sport(string n, string sn, int w, int mp, int i);

	//definire destructor (cerinta 3)
	~Sport();
};