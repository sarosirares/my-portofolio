#include <iostream>
#include "Punct.h"
#include "Complex.h"
using namespace std;

	void main()
	{
		Point p(10, -3);
		p.display();
		Circle c(-1, 10, 4);
		c.display();
		Square pa(4, -1, 5);
		pa.display();
		cout << "point color= " << p.colorcode << endl;
		c.colorcode = 7;
		cout << "the circle has given for point the color " << c.colorcode << endl;
	}

