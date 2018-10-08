#pragma once
//#include<iostream>
class Rational
{
public:
	int numer, denom;
	Rational();
	Rational(int number);
	Rational(int n, int d);
	void simplify(); //Функция упрощения
	Rational& operator +=(const Rational& r); //Оператор добавления
	Rational operator +(const Rational& r) const; //Оператор сложения
	Rational operator -() const; //Оператор отрицания (унарный минус)
	Rational& operator -(const Rational& r); //Оператор уменьшения
	Rational& operator ++(); // префикс
	Rational operator ++(int); // постфикс
	Rational& operator *=(const Rational& r); //Оператор умножения
	Rational& operator /(const Rational& r); //Оператор деления
	Rational operator *(const Rational& r) const;
	Rational sqr();
	bool operator ==(const Rational& r) const; //Оператор сравнения ==
	bool operator !=(const Rational& r) const;//Оператор сравнения !=
	bool operator <(Rational& r);
	operator int() const; //Оператор преобразования типов 
	operator double() const; //Оператор преобразования типов 
	/*friend istream& operator >>(istream& in, Rational& r); //Оператор ввода
	friend ostream& operator <<(ostream& out, const Rational& r); //Оператор вывода*/
};
