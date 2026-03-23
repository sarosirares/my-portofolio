#include <iostream>
#include <vector>
#include "Student2.h"
using namespace std;

class Student {
private:
	string nume;
	int varsta;
	int anStudii;
	double medieAnPrecedent;
public:
	//metode publice
	void talk(string mesaj);
	bool activ();

	void set_Nume(string name)
	{
		nume = name;
	}
	string get_Nume()
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

	void Student::set_Varsta(int age)
	{
		varsta = age;
	}
	int Student::get_Varsta()
	{
		return varsta;
	}

	void Student::set_AniStudii(int ani)
	{
		anStudii = ani;
	}
	int Student::get_AniStudii()
	{
		return anStudii;
	}
	void Student::set_MedieAnPrecedent(double grade)
	{
		medieAnPrecedent = grade;
	}
	double Student::get_MedieAnPrecedent()
	{
		return medieAnPrecedent;
	}

	int main()
	{
		Student Dan;
		Student Elena;

		Student2 Dan2;
		Dan2.set_AniStudii(1);



		Dan.set_AniStudii(3);
		Dan.set_MedieAnPrecedent(9.10f);
		Dan.set_Nume("Dan");
		Dan.get_AniStudii();

		Elena.set_Nume("Elena");
		Elena.set_MedieAnPrecedent((double)9.40);
		Elena.set_AniStudii(2);

		Student* Mariana = new Student();
		(*Mariana).set_AniStudii(1);
		Mariana->set_Nume("Mariana");
		Mariana->set_MedieAnPrecedent((double)8.95);

		vector<Student> vctStudent{ Dan };
		vctStudent.push_back(Elena);
	}