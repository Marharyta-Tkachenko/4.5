#pragma once
#include "Pair.h"

class Complex : public Pair
{
private:
	double x, y;

public:
	Complex();
	Complex(double x, double y);
	Complex(const Complex& v);

	double GetX() const;
	double GetY() const;

	void SetX(double);
	void SetY(double);

	virtual Complex* operator = (Pair* r);

	virtual Complex* operator + (Pair* Z);
	virtual Complex* operator - (Pair* Z);
	virtual Complex* operator * (Pair* Z);
	virtual Complex* operator / (Pair* Z);
	friend bool operator == (Complex&, Complex&);
	Complex& Conj();

	virtual ostream& Print(ostream& out) const;
	virtual istream& Insert(istream& in);
};

