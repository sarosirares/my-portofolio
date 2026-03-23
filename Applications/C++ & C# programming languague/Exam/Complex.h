class Complex
{
	friend bool operator > (Complex&, Complex&);
	friend bool operator >= (Complex&, Complex&);
	friend bool operator == (Complex&, Complex&);
	friend bool operator != (Complex&, Complex&);
	friend bool operator <= (Complex&, Complex&);
	friend bool operator < (Complex&, Complex&);
private:
	double Re;
	double Im;
public:
	inline Complex() {}
	inline Complex(double re, double im) { Re = re; Im = im; }
	void ToString();
};

void sort(Complex[], int);