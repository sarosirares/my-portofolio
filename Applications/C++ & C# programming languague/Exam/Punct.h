#pragma once
#include <math.h>
class Point
{
protected:
	int x;
	int y;
public:
	int colorcode;
public:
	Point(int cx = 0, int cy = 0) { x = cx; y = cy; colorcode = 0; };
	void display();
};
class Circle : public Point
{
private:
	int radius;
public:
	Circle(int xx, int yy, int rr)
	{
		x = xx;
		y = yy;
		radius = rr;
	}
	void display();
};
class Square : private Point
{
private:
	int side;
public:
	Square(int xx, int yy, int l)
	{
		x = xx;
		y = yy;
		side = l;
	}
	void display();
};