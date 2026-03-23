#include <iostream>
#include "Jucator.h"
using namespace std;

int main()
{
	{
		Jucator Dan;
		//1
		display_Jucator(Dan);
		//2
		Jucator Marius{ Dan }; //initializam un Obiect Marius prin copierea membrilor obiectului Dan

		Jucator Messi{ "Messi", 100, 10 };
		Jucator Ronaldo{ "Ronaldo" };
		Jucator Mbape{ "Mbape" };
		//in interior putem folosi obiectele create
	}   //in exterior se apeleaza destructorul de 4 ori
	Jucator* Pele = new Jucator("Pele", 75, 9);
	delete Pele; //se apeleaza destructorul pentru poiter
}