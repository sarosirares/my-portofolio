#include <iostream>
using namespace std;

class Base
{
public:
	void say_hello() const
	{
		cout << "Hello - I'm a Base class object" << endl;
	}
};

class Derived : public Base
{
public:
	void say_hello() const
	{
		cout << "Hello - I'm a Derived class object" << endl;
	}
};

void greetings(const Base& obj)
{
	cout << "Greetings: ";
	obj.say_hello();
}

int main()
{
	Base b;
	b.say_hello();

	Derived d;
	d.say_hello();

	greetings(b);
	greetings(d);

	//same happens if we have a pointer
	Base* ptr = new Derived(); //ptr can hold the address of any Base object
	ptr->say_hello();

	delete ptr;

	return 0;