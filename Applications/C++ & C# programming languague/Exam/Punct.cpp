#include "Punct.h"
#include <iostream>
using namespace std;
void Point::display() { cout << "point[" << x << "," << y << "]" << endl; };
void Circle::display() { cout << "radius= " << radius << " center= "; Point::display(); };
void Square::display() { cout << "side= " << side << " left upper corner= "; Point::display(); };