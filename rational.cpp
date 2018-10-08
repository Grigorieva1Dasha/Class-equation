#include<iostream>
#include<math.h>
#include"rational.h"

using namespace std;

Rational::Rational()
{
	numer = 0;
	denom = 1;
}
Rational::Rational(int number)
{
	numer = number;
	denom = 1;
}
Rational::Rational(int n, int d)
{
	numer = n;
	denom = d;
}
Rational& Rational::operator +=(const Rational& r)
{
	numer = (numer*r.denom + denom * r.numer);
	denom *= r.denom;
	simplify(); // упрощение
	return *this;
}
Rational Rational::operator +(const Rational &r) const
{
	// this - указатель на себя
	// *this - ссылка на себя
	Rational res(*this);
	// Используем готовую операцию добавления
	return res += r;
}
void Rational::simplify()
{
	if (denom < 0)
	{
		numer = -numer;
		denom = -denom;
	}
	for (int i = 2; i <= abs(denom) && i <= abs(numer); i++)
		if (numer % i == 0 && denom % i == 0)
		{
			numer /= i;
			denom /= i;
			i--;
		}
}
Rational Rational::operator -() const
{
	Rational r(-numer, denom);
	return r;
}
Rational& Rational::operator -(const Rational& r)
{
	return (*this += (-r));
}
Rational& Rational::operator ++()
{
	numer += denom;
	return *this;
}
Rational Rational::operator ++(int)
{
	Rational r(*this);
	numer += denom;
	return r;
}
bool Rational::operator ==(const Rational& r) const
{
	return (numer == r.numer) && (denom == r.denom);
}
bool Rational::operator !=(const Rational& r) const
{
	return !(*this == r);
}
bool Rational::operator <(Rational& r){
	if (denom != r.denom){
		numer *= r.denom;
		r.numer *= denom;
		denom = denom * r.denom;
		r.denom = denom;
	}
	return (numer < r.numer);
}
Rational::operator int() const
{
	return numer / denom;
}
Rational::operator double() const
{
	return ((double)numer) / denom;
}
Rational& Rational::operator *=(const Rational& r)
{
	numer *= r.numer;
	denom *= r.denom;
	simplify();
	return *this;
}
Rational& Rational::operator /(const Rational& r)
{
	numer *= r.denom;
	denom *= r.numer;
	simplify();
	return *this;
}
Rational Rational::operator *(const Rational& r) const{
	Rational res(*this);
	return res *= r;
}
Rational Rational::sqr(){
	Rational r(*this);
	int num = round(sqrt(double(r.numer)));
	int den = round(sqrt(double(r.denom)));
	return Rational(num, den);
}
/*istream& operator >>(istream& in, Rational& r)
{
	in >> r.numer >> r.denom;
	return in;
}
ostream& operator <<(ostream& out, const Rational& r)
{
	out << r.numer << "/" << r.denom;
	return out;
}*/
