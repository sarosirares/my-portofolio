#include <iostream>
#include "Sport.h"
using namespace std;

int main()
{
	/*
	
		Lab1


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
	*/

	//Lab2
	cout << "Active players: " << Sport::get_contor() << endl << endl;

	{
		//Cerinta 2
		Sport Dan{ 30, 78, 2 };
		cout << "Active players: " << Dan.get_contor() << endl << endl;
		Sport Vasile{ "Vasile", "Tenis", "Calin", 47 };
		cout << "Active players: " << Vasile.get_contor() << endl << endl;

		//Cerinta 4
		Sport Simona{ "Simona", 12 };
		cout << "Active players: " << Simona.get_contor() << endl << endl;
		Sport Mihai{ "Mihai" };
		cout << "Active players: " << Dan.get_contor() << endl << endl;

		//Cerinta 5
		Sport Rares{ "Rares", "Football", 10, 12, 0 };
		cout << "Active players: " << Simona.get_contor() << endl << endl;

		//Cerinta 8
		const Sport Mircea{ "Mircea", "Tenis", "Cosmin", 120, 265, 3 };
		cout << "Valoarea de la cerinta 8 (obiect constant): " << Mircea.get_cerinta8() << endl;
		cout << "Active players: " << Dan.get_contor() << endl << endl;
	}

	cout << "Active players: " << Sport::get_contor() << endl;

	return 0;
}