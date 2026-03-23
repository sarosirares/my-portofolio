#include "Classes.h"
#include <iostream>
using namespace std;

Figure::Figure() { cout << " Constructor Figure " << endl; };
Figure::~Figure() { cout << " Destructor Figure " << endl; };
void Figure::Draw() { cout << " Draw a Figure object " << endl; };
Circle::Circle() { cout << " Constructor Circle " << endl; };
Circle::~Circle() { cout << " Desructor Circle " << endl; };
void Circle::Draw() { cout << " Draw a Circle object " << endl; };
Square::Square() { cout << " Constructor Square " << endl; };
Square::~Square() { cout << " Destructor Square " << endl; };
void Square::Draw() { cout << " Draw a Square object " << endl; };