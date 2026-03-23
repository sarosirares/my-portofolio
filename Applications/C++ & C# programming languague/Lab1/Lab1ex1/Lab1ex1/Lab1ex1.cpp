#include <iostream>
#include <vector>
using namespace std;

class Student {
public:
	//atribute
	string nume;
	int varsta;
	int anStudii;
	double medieAnPrecedent;

	//metode
	void talk(string mesaj) { cout << "Hello world" << endl;}
	bool activ();

};

int main()
{
	Student Dan;
	Student Elena;

	Dan.anStudii = 3;
	Dan.medieAnPrecedent = 9.10f;
	Dan.nume = "Dan";

	Dan.talk("Eu sunt Dan");

	Elena.anStudii = 1;
	Elena.medieAnPrecedent = (double)9.50;
	Elena.nume = "Elena";

	Student* Mariana = new Student();
	(*Mariana).anStudii = 2;
	Mariana->medieAnPrecedent = (double)8.95;

	(*Mariana).talk("abc");

	vector<Student> vctStudenti{ Dan };
	vctStudenti.push_back(Elena);

	return 0;
}