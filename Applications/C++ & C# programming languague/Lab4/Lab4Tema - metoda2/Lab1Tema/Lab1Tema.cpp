#include <iostream>
#include "Sport.h"
#include "Healthy_Diet.h"
#include "Retired.h"
#include "Active.h"
#include "Pro.h"

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

	/*
	
		Lab2

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

	*/

	/*

		Lab3

	Sport Mircea{ "Mircea", "Tenis", "Cosmin", 120, 265, 3 };

	cout << endl;

	Retired Dan;
	Dan.set_AthleteName("Dan");						//method called from A
	Dan.set_water(3);								//method called from A
	cout << "(" << Dan.get_AthleteName() << ") ";	//method called from A
	Dan.Retired_E_access();							//method called from E (from C) 

	cout << endl;

	Active Mihai;
	Mihai.set_AthleteName("Mihai");					//method called from A
	Mihai.suspended = 8;						    //atribute from B
	Mihai.set_MatchesPlayed(30);					//method called from B (override)
	cout << Mihai.get_AthleteName() << " has " << Mihai.get_MatchesPlayed() << " matches played." << " (Suspentions: " << Mihai.suspended << ")" << endl;

	cout << endl;

	Pro Coman;
	Coman.set_AthleteName("Coman");					//method called from A
	Coman.years_activity = 16;						//atribute from B (Pro is a Active)
	Coman.set_Wins(356);							//method called from A
	Coman.suspended = 2;							//atribute from B (Pro is a Active)
	Coman.set_MatchesPlayed(612);					//method called from B
	cout << Coman.get_AthleteName() << " has " << Coman.get_MatchesPlayed() << " matches played." << " (Suspentions: " << Coman.suspended << ")" << endl;
	cout << "(" << Coman.get_AthleteName() << ") ";	//method called from A
	Coman.Active_E_access();						//method called from B

	cout << endl;

	*/

	//Lab4

Active Mihai = *new Active();
Mihai.set_AthleteName("Mihai");
Mihai.years_activity = 8;
Mihai.suspended = 4;

Pro Edi;
Edi.set_AthleteName("Edi");
Edi.years_activity = 17;
Edi.suspended = 67;

Active* ptr1 = new Active();
Active* ptr2 = new Pro();

ptr1->set_AthleteName("ptr1");
ptr1->years_activity = 4;
ptr1->suspended = 10;

ptr2->set_AthleteName("ptr2");
ptr2->years_activity = 21;
ptr2->suspended = 126;

//Lab4ex1

cout << " \n === Static Bindind ===" << endl;
cout << "\nCalled by objects:" << endl;
Mihai.display_years_activity();		//class Active
Edi.display_years_activity();		//class Pro
cout << "\nCalled by pointers:" << endl;
ptr1->display_years_activity();		//class Active
ptr2->display_years_activity();		//class Pro

//Lab4ex2

cout << " \n === Dynamic Binding ===" << endl;
cout << "\nCalled by objects:" << endl;
Mihai.display_suspended();		//class Active
Edi.display_suspended();		//class Pro
cout << "\nCalled by pointers:" << endl;
ptr1->display_suspended();		//class Active
ptr2->display_suspended();		//class Pro


//-----------------------------------------------

Retired Dan;
Dan.set_AthleteName("Dan");

//Lab4ex3

Sport Gabriel;
Gabriel.set_SportName("Tenis");
Gabriel.set_AthleteName("Gabriel");

cout << " \n === Interface === \n" << endl;

Gabriel.display_activity();
Gabriel.display_atname();

cout << endl << endl;

delete ptr1;
delete ptr2;

return 0;
}