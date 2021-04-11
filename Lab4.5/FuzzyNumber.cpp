#include "FuzzyNumber.h"

FuzzyNumber::FuzzyNumber()
	: x(0), l(0), r(0)
{}

FuzzyNumber::FuzzyNumber(double x, double l, double r)
{
	if (x > (x - l) && (x + r) > x)
	{
		SetX(x); SetL(l); SetR(r);
	}
	else
	{
		SetX(0); SetL(0); SetR(0);
	}
}

FuzzyNumber::FuzzyNumber(const FuzzyNumber& v)
	: x(v.x), l(v.l), r(v.r)
{}

FuzzyNumber* FuzzyNumber::operator = (Pair* r)
{
	this->SetL(GetL());
	this->SetR(GetR());
	this->SetX(GetX());
	return this;
}


FuzzyNumber* FuzzyNumber::operator + (Pair* Z)
{
	FuzzyNumber* T = new FuzzyNumber();
	T->SetX(this->GetX() + ((FuzzyNumber*)Z)->GetX());
	T->SetL(this->GetX() + ((FuzzyNumber*)Z)->GetX() - this->GetL() - ((FuzzyNumber*)Z)->GetL());
	T->SetR(this->GetX() + ((FuzzyNumber*)Z)->GetX() + this->GetR() + ((FuzzyNumber*)Z)->GetR());
	return T;
}

FuzzyNumber* FuzzyNumber::operator - (Pair* Z)
{
	FuzzyNumber* T = new FuzzyNumber();
	T->SetX(this->GetX() - ((FuzzyNumber*)Z)->GetX());
	T->SetL(this->GetX() - ((FuzzyNumber*)Z)->GetX() - this->GetL() - ((FuzzyNumber*)Z)->GetL());
	T->SetR(this->GetX() - ((FuzzyNumber*)Z)->GetX() + this->GetR() + ((FuzzyNumber*)Z)->GetR());
	return T;
}

FuzzyNumber* FuzzyNumber::operator * (Pair* Z)
{
	FuzzyNumber* T = new FuzzyNumber();
	T->SetX(this->GetX() * ((FuzzyNumber*)Z)->GetX());
	T->SetL(this->GetX() * ((FuzzyNumber*)Z)->GetX() - ((FuzzyNumber*)Z)->GetX() * this->GetL() - this->GetX() * ((FuzzyNumber*)Z)->GetL() - this->GetL() * ((FuzzyNumber*)Z)->GetL());
	T->SetR(this->GetX() * ((FuzzyNumber*)Z)->GetX() + ((FuzzyNumber*)Z)->GetX() * this->GetR() + this->GetX() * ((FuzzyNumber*)Z)->GetR() + this->GetR() * ((FuzzyNumber*)Z)->GetR());
	return T;
}

FuzzyNumber* FuzzyNumber::operator / (Pair* Z)
{
	FuzzyNumber* T = new FuzzyNumber();
	if (((FuzzyNumber*)Z)->GetX() > 0 && (((FuzzyNumber*)Z)->GetX() + ((FuzzyNumber*)Z)->GetR()) > 0 && (((FuzzyNumber*)Z)->GetX() - ((FuzzyNumber*)Z)->GetL()) > 0)
	{
		T->SetX(this->GetX() / ((FuzzyNumber*)Z)->GetX());
		T->SetL((this->GetX() - this->GetL()) / (((FuzzyNumber*)Z)->GetX() + ((FuzzyNumber*)Z)->GetR()));
		T->SetR((this->GetX() + this->GetR()) / (((FuzzyNumber*)Z)->GetX() - ((FuzzyNumber*)Z)->GetL()));
	}
	else
	{
		cout << "FuzzyNumbers can't be divided" << endl;
	}
	return T;
}

FuzzyNumber operator / (int a, const FuzzyNumber Z)
{
	FuzzyNumber T(0, 0, 0);
	T.SetX(a / Z.GetX());
	T.SetL(a / (Z.GetX() + Z.GetL()));
	T.SetR(a / (Z.GetX() - Z.GetR()));
	return T;
}

ostream& FuzzyNumber::Print(ostream& out) const
{
	out << "(" << GetL() << "; " << x << "; " << GetR() << ")" << endl;
	return out;
}

istream& FuzzyNumber::Insert(istream& in)
{
	double x, l, r;
	do
	{
		cout << "x = "; in >> x;
		cout << "l = "; in >> l;
		cout << "r = "; in >> r;
	} while (!(x > (x - l) && (x + r) > x));
	this->SetX(x); this->SetL(l); this->SetR(r);
	return in;
}