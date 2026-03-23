#pragma once
#include <string>

class Student2
{
private:
	std::string nume;
	int varsta;
	int anStudii;
	double medieAnPrecedent;
public:
	//metode publice
	void talk(std::string mesaj);
	bool activ();

	void set_Nume(std::string name)
	{
		nume = name;
	}
	std::string get_Nume()
	{
		return nume;
	}

	void set_Varsta(int age);
	int get_Varsta();

	void set_AniStudii(int year);
	int get_AniStudii();

	void set_MedieAnPrecedent(double grade);
	double get_MedieAnPrecedent();
};

