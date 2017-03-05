#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>

namespace CS1124 {
	
	class Rational{
		int num, den;
	public:
		Rational();
		Rational(const int num);
		Rational& operator+=(const Rational& second);
		Rational& operator++();
		Rational operator++(int x);
		int greatestCommonDivisor(int x, int y);
		void simplify();
		void setNum(int num);
		void setDen(int den);
		int getNum() const;
		int getDen() const;
	};

	Rational operator+(Rational first, const Rational& second);
	bool operator==(Rational& first, Rational& second);
	bool operator==(int first, Rational& second);
	bool operator!=(Rational& first, Rational& second);
	Rational& operator--(Rational& first);
	Rational operator--(Rational& first, int x);
	std::istream& operator>>(std::istream& is, Rational& rational);
	std::ostream& operator<<(std::ostream& os, Rational& rational);
}

#endif