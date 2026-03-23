#pragma once
class Figure
{
public:
	Figure();
	virtual ~Figure();
	virtual void Draw();
};
class Circle : public Figure
{
public:
	Circle();
	virtual ~Circle();
	virtual void Draw();
};
class Square : public Figure
{
public:
	Square();
	virtual ~Square();
	virtual void Draw();
};
