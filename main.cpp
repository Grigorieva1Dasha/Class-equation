#include<iostream>
#include<locale.h>
#include"rational.h"

using namespace std; 

istream& operator >>(istream& in, Rational& r)
{
	in >> r.numer >> r.denom;
	return in;
}
ostream& operator <<(ostream& out, const Rational& r)
{
	out << r.numer << "/" << r.denom;
	return out;
}

int main() {
	setlocale(LC_ALL, "Russian");

	/*cout << "Первый тест:" << endl;
	Rational a(1, 2), b(-1, 6);
	cout << "a=" << a << " b=" << b << " a+b=" << a + b << endl;
	cout << "a(" << a << ")*= b(" << b << ")" << endl;
	a *= b;
	cout << a << endl;
	cout << "a=" << a << " b=" << b << " a-b=" << a - b << endl;
	Rational c = 3;
	cout << "b=" << b << " c=" << c << " b/c=" << b / c << endl << endl;

	cout << "Второй тест:" << endl;
	Rational e(7, 8), f(5, 12);
	cout << "e=" << e << " f=" << f << " e+f=?" << endl;
	cout << "Введите результат g=m/n в формате: m n" << endl;
	Rational g;
	cin >> g;
	if (e + f != g)
		cout << "Неправильно! e+f=" << e + f << endl;
	else
		cout << "Правильно!" << endl;*/

	Rational a1,b1,c1,d,x1,x2;
	cout << "Решение квадратного уравнения: " << endl;
	cout << "Введите коэфициенты a, b, c (a=m/n, введите m n): " << endl;
	cout << "a= ";
	cin >> a1;
	cout << "b= ";
	cin >> b1;
	cout << "c= ";
	cin >> c1;
	cout << "("<< a1 << ")x^2 + (" << b1 << ")x + (" << c1 << ") = 0" << endl;
	if (a1==Rational(0)){
		cout << "Это не квадратное уравнение!" << endl;
		system("pause");
		return 0;
	}
	Rational q = 4;
	d = b1 * b1 - q * a1 * c1;
	cout << "Дискриминант = " << d << endl;
	Rational null = 0;
	Rational w = 2;
	if (d < null){
		cout << "Дискриминант < 0, нет решений!" << endl;
		system("pause");
		return 0;
	}
	else if(d == null){
		x1 = (-b1)/ w / a1;
		cout << "x1 = x2 = " << x1 << endl;
		system("pause");
		return 0;
	}
	else{
		double d2 = d.sqr();
		x1 = (-b1 + Rational(d2)) / w / a1;
		x2 = (-b1 - Rational(d2)) / w / a1;
		cout << "x1 = " << x1 << endl;
		cout << "x2 = " << x2 << endl;
	}
	system("pause");
	return 0;
}
