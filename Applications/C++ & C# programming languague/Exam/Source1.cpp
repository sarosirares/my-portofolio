#include <iostream>
using namespace std;
struct point
{
	int x;
	int y;
};
struct circle
{
	point center;
	int radius;
};
void main()
{
	point p, * pp;
	p.x = 7; p.y = 11;
	cout << "p = p[" << p.x << "," << p.y << "]" << endl;
	pp = &p;
	//pp->x = 12; pp->y = 9;
	cout << "pp = pp[" << pp->x << "," << pp->y << "]" << endl;
	circle c;
	c.center.x = 7;
	c.center.y = -9;
	//c.center = *pp;
	c.radius = 12;
	cout << "c radius=" << c.radius << " center[" << c.center.x << "," << c.center.y << "]";
}