#include "Rational.h"
#include <iostream>

using namespace std;

namespace CS1124{
	Rational::Rational() {};

	Rational::Rational(const int num) : num(num), den(1) {}

	int Rational::greatestCommonDivisor(int x, int y) {
		while (y != 0) {
			int temp = x % y;
			x = y;
			y = temp;
		}
		return x;
	}

	void Rational::simplify() {
		int gcd = greatestCommonDivisor(num, den);
		num /= gcd;
		den /= gcd;
	}

	Rational& Rational::operator+=(const Rational& second) {
		int a = getNum();
		int b = getDen();
		int c = second.getNum();
		int d = second.getDen();
		int num = (a * d) + (b * c);
		int den = b * d
		setNum(num);
		setDen(den);
		
		return *this;
	}

	Rational operator+(Rational first, const Rational& second) {
		first += second;
		return first;
	}

	bool operator==(Rational& first, Rational& second) {
		first.simplify();
		second.simplify();
		if (first.getNum() == second.getNum()) {
			if (first.getDen() == second.getDen()) {
				return true;
			}
		}
		return false;
	}

	bool operator==(int first, Rational& second) {
		Rational temp(first);
		return (temp == second);
	}

	bool operator!=(Rational& first, Rational& second) {
		return !(first == second);
	}

	Rational& Rational::operator++() {
		int add = getDen();
		int num = getNum();
		num += add;
		setNum(num);

		return *this;
	}

	Rational& operator--(Rational& first) {
		int sub = first.getDen();
		int num = first.getNum();
		num -= sub;
		first.setNum(num);
		return first;
	}

	Rational operator--(Rational& first, int x) {
		Rational temp(first);
		--first;
		return temp;
	}

	Rational Rational::operator++(int x) {
		Rational temp(*this);
		++(*this);
		return temp;
	}

	int Rational::getNum() const {
		return num;
	}

	int Rational::getDen() const {
		return den;
	}
	void Rational::setNum(int num) {
		this->num = num;
	}

	void Rational::setDen(int den) {
		this->den = den;
	}

	std::istream& operator>>(std::istream& is, Rational& rational) {
		int num, den;
		char junk;
		is >> num >> junk >> den;
		rational.setNum(num);
		rational.setDen(den);
		return is;
	}

	std::ostream& operator<<(std::ostream& os, Rational& rational) {
		rational.simplify();
		os << rational.getNum() << "/" << rational.getDen();
		return os;
	}
}