#pragma once
#include <iostream>
using namespace std;

class Punct
{
private:

	int x;
	int y;

public:

	Punct() {}
	Punct(int cx, int cy)
	{
		x = cx;
		y = cy;
	}

	void setx(int cx)
	{
		x = cx;
	}

	int getx()
	{
		return x;
	}

	void sety(int cy)
	{
		x = cy;
	}

	int gety()
	{
		return y;
	}
};

class Figura

