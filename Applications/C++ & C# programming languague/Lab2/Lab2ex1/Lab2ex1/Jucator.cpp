#include "Jucator.h"
Jucator::Jucator(const Jucator& source)
	:nume(source.nume),
	sanatate(source.sanatate),
	experienta(source.experienta) {
	cout << "Constructor copiere - am copiat: " << source.nume << endl;
}

void display_Jucator(Jucator j)
{
	cout << "Nume: " << j.get_name() << endl;
	cout << "Sanatate: " << j.get_health() << endl;
	cout << "Experienta: " << j.get_exp() << endl;
}