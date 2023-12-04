#include <rational/rational.hpp>

#include <iostream>
#include <sstream>

//конструктор
Rational::Rational(const int64_t& first, const int64_t& second) {
	if (second > 0) {
		num_ = first / nod(first, second);
		den_ = second / nod(first, second);
	}
	if (second < 0) {
		num_ = -first / nod(first, -second);
		den_ = -second / nod(first, -second);
	}
	if (second == 0) {
			throw std::invalid_argument("Zero denumenator in Rational ctor");
	}
}
Rational::Rational(const int64_t& first) {
	num_ = first;
	den_ = 1;
}

//ввод
std::istream& Rational::ReadFrom(std::istream& istrm) {
	int64_t f(0), s(0);
	char znak;
	istrm >> f >> znak >> s;
	if (istrm.good()) {
		if (znak == '/' && s != 0) {
			num_ = f;
			den_ = s;
		} else {
			istrm.setstate(std::ios_base::failbit);
		}
	}
	return istrm;
}

//вывод
std::ostream& Rational::WriteTo(std::ostream& ostrm) const {
	ostrm << num_ << sign << den_;
	return ostrm;
}

//operator += -= *= /=
Rational& Rational::operator+=(const Rational& x) {
	int64_t num_1 = num_;
	int64_t den1 = den_;
	num_ = (num_1 * x.den_) + (x.num_ * den1);
	den_ = den1 * x.den_;
	norm();
	return *this;
}
Rational& Rational::operator-=(const Rational &x) {
	int64_t num_1 = num_;
	int64_t den1 = den_;
	num_ = (num_1 * x.den_) - (x.num_ * den1);
	den_ = den1 * x.den_;
	norm();
	return *this;
}

Rational& Rational::operator*=(const Rational& x) {
	num_ *= x.num_;
	den_ *= x.den_;
	norm();
	return *this;
}

Rational& Rational::operator/=(const Rational& x) {
	if (x.num_ == 0) {
		throw std::invalid_argument("Zero denumenator in Rational ctor");
	}
	num_ *= x.den_;
	den_ *= x.num_;
	norm();
	return *this;
}

//operator r + r, d + r, r + d
Rational operator+(const Rational& x, const Rational& y) {
	return Rational(x) += y;
}
Rational operator+(const Rational& x, const int64_t& y) {
	return Rational(x) += Rational(y);
}
Rational operator+(const int64_t& x, const Rational& y) {
	return Rational(x) += Rational(y);
}

//operator r - r, d - r, r - d
Rational operator-(const Rational& x, const Rational& y) {
	return Rational(x) -= y;
}
Rational operator-(const Rational& x, const int64_t& y) {
	return Rational(x) -= Rational(y);
}
Rational operator-(const int64_t& x, const Rational& y) {
	return Rational(x) -= Rational(y);
}

//operator r * r, d * r, r * d
Rational operator*(const Rational& x, const Rational& y) {
	return Rational(x) *= y;
}
Rational operator*(const Rational& x, const int64_t& y) {
	return Rational(x) *= Rational(y);
}
Rational operator*(const int64_t& x, const Rational& y) {
	return Rational(x) *= Rational(y);
}


//operator r / r, d / r, r / d
Rational operator/(const Rational& x, const Rational& y) {
	return Rational(x) /= y;
}
Rational operator/(const Rational& x, const int64_t& y) {
	return Rational(x) /= Rational(y);
}
Rational operator/(const int64_t& x, const Rational& y) {
	return Rational(x) /= Rational(y);
}