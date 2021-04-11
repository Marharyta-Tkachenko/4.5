#pragma once
#include "Pair.h"

class FuzzyNumber : public Pair
{
private:
	double x, l, r;

public:
	FuzzyNumber();
	FuzzyNumber(double x, double l, double r);
	FuzzyNumber(const FuzzyNumber& v);

	double GetX() const { return x; }
	double GetL() const { return l; }
	double GetR() const { return r; }

	void SetX(double value) { x = value; }
	void SetL(double value) { l = value; }
	void SetR(double value) { r = value; }

	virtual FuzzyNumber* operator = (Pair* r);

	virtual FuzzyNumber* operator + (Pair* Z);
	virtual FuzzyNumber* operator - (Pair* Z);
	virtual FuzzyNumber* operator * (Pair* Z);
	virtual FuzzyNumber* operator / (Pair* Z);
	friend FuzzyNumber operator / (int a, const FuzzyNumber Z);

	virtual ostream& Print(ostream& out) const;
	virtual istream& Insert(istream& in);
};
