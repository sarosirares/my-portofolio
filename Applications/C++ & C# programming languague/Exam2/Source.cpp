#include <iostream>
#include "Classes.h"
using namespace std;


void main()
{
	for (int i = 0; i < 1; i++)
	{
		Figure* pf[3];
		pf[0] = new Figure();
		pf[1] = new Circle();
		pf[2] = new Square();
		for (int i = 0; i < 3; i++)
			pf[i]->Draw();
		for (i = 0; i < 3; i++)
			delete pf[i];
	}
}