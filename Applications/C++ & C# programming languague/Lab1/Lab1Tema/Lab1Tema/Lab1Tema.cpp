#include <iostream>
#include "Sport.h"
using namespace std;

int main()
{
	Sport Luca;
	Sport *Mihai = new Sport();

	Luca.set_AthleteName("Luca");
	Luca.set_SportName("Tennis");
	Luca.set_CoachName("Dan");
	Luca.set_Wins(52);
	Luca.set_MatchesPlayed(100);
	Luca.set_Injuries(2);

	cout << "Name: " << Luca.get_AthleteName() << endl;
	cout << "Sport: " << Luca.get_SportName() << endl;
	cout << "Coach name: " << Luca.get_CoachName() << endl;
	cout << "Wins: " << Luca.get_Wins() << endl;
	cout << "Matches: " << Luca.get_MatchesPlayed() << endl;
	cout << "Injuries: " << Luca.get_Injuries() << endl;

	cout << endl;

	Mihai->set_AthleteName("Mihai");
	(*Mihai).set_SportName("Football");
	Mihai->set_CoachName("Calin");
	(*Mihai).set_Wins(39);
	Mihai->set_MatchesPlayed(60);
	Mihai->set_Injuries(0);

	cout << "Name: " << Mihai->get_AthleteName() << endl;
	cout << "Sport: " << Mihai->get_SportName() << endl;
	cout << "Coach name: " << (*Mihai).get_CoachName() << endl;
	cout << "Wins: " << Mihai->get_Wins() << endl;
	cout << "Matches: " << Mihai->get_MatchesPlayed() << endl;
	cout << "Injuries: " << Mihai->get_Injuries() << endl;

	delete Mihai;

	return 0;
}