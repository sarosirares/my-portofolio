#include <iostream>
#include <string>
using namespace std;

class Jucator
{
private:
	string nume;
	int sanatate;
	int experienta;
public:

	string get_name() { return nume; }
	int get_health() { return sanatate; }
	int get_exp() { return experienta; }

	//constructor copiere
	Jucator(const Jucator& source);

	//constructor methods
	Jucator(string name, int health, int xp) : nume{name}, sanatate{health}, experienta{xp}
	{
		cout << "Constructor cu 3 params" << endl;
	}
	Jucator() : Jucator{ "Gol", 0, 0 }
	{
		cout << "Constructor fara parametrii" << endl;
	}
	Jucator(string name) : Jucator{ name,0 ,0 }
	{
		cout << "Constructor cu 1 param string" << endl;
	}
	//destructor
	~Jucator()
	{
		cout << "Apelarea destructorului de catre: " << nume << endl;
	}
};

void display_Jucator(Jucator j);