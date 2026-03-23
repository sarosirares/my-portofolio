#include <iostream>
using namespace std;
int citziua();
void main()
{
	int zi;
	try
	{
		zi = citziua();
		switch (zi)
		{
		case 1: cout << "Monday" << endl;
		case 2: cout << "Tuesday" << endl;
		case 3: cout << "Wednesday" << endl;
		case 4: cout << "Thursday" << endl;
		case 5: cout << "Friday" << endl;
		case 6: cout << "Saturday" << endl;
		case 7: cout << "Sunday" << endl;;
		}
	}
	catch (int *ex)
	{
		cout << *ex << endl;
	}
	cout << "Bye";
}
int citziua()
{
	int zi;
	cout << "Give the day of the week [1,7] ";
	cin >> zi;
	if (zi < 1 || zi >7)
		throw new int (zi);
	else
		return zi;
}
