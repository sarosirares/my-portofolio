#include "Complex.h"
#include <iostream>
using namespace std;

void Complex::ToString()
{
	if (Im > 0) cout << Re << " + j" << Im;
	else cout << Re << " - j" << abs(Im); cout;
}
bool operator > (Complex& x, Complex&y)
{
	return ((sqrt(x.Re * x.Re + x.Im * x.Im) > sqrt(y.Re * y.Re + y.Im * y.Im)));
}
bool operator >= (Complex& x, Complex& y)
{
	return ((sqrt(x.Re * x.Re + x.Im * x.Im) >= sqrt(y.Re * y.Re + y.Im * y.Im)));
}
bool operator == (Complex& x, Complex& y)
{
	return ((sqrt(x.Re * x.Re + x.Im * x.Im) == sqrt(y.Re * y.Re + y.Im * y.Im)));
}
bool operator != (Complex& x, Complex& y)
{
	return ((sqrt(x.Re * x.Re + x.Im * x.Im) != sqrt(y.Re * y.Re + y.Im * y.Im)));
}
bool operator <= (Complex& x, Complex& y)
{
	return ((sqrt(x.Re * x.Re + x.Im * x.Im) <= sqrt(y.Re * y.Re + y.Im * y.Im)));
}
bool operator < (Complex& x, Complex& y)
{
	return ((sqrt(x.Re * x.Re + x.Im * x.Im) < sqrt(y.Re * y.Re + y.Im * y.Im)));
}

void sort(Complex sir[], int dim)
{
	for (int i = 0; i < dim; i++)
	{
		for (int j = i + 1; j < dim; j++)
		{
			if (sir[j] < sir[i])
			{
				Complex temp = sir[i];
				sir[i] = sir[j];
				sir[j] = temp;
			}
		}
	}
}