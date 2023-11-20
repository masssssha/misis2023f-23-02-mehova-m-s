#ifndef RATIONAL_HPP
#define RATIONAL_HPP
#include <iostream>
#include <sstream>

class Rational {
	public:
		Rational() = default;
		~Rational() = default;
		Rational(const Rational& x) = default;
		Rational(const int& first, const int& second);
		Rational(const int& first);
		Rational& operator=(const Rational&) = default;
		std::istream& ReadFrom(std::istream& istrm);
		std::ostream& WriteTo(std::ostream& ostrm) const;
		bool operator==(const Rational& x) const { return num_ * x.den_ - x.num_ * den_ == 0; }
		bool operator!=(const Rational& x) const { return !operator==(x); }
		bool operator>(const Rational& x) const { return num_ * x.den_ - x.num_ * den_ > 0; }
		bool operator<(const Rational& x) const { return num_ * x.den_ - x.num_ * den_ < 0; }
		bool operator>=(const Rational& x) const { return num_ * x.den_ - x.num_ * den_ >= 0; }
		bool operator<=(const Rational& x) const { return num_ * x.den_ - x.num_ * den_ <= 0; }
		Rational operator+=(const Rational& x);
		Rational operator-=(const Rational& x);
		Rational operator*=(const Rational& x);
		Rational operator/=(const Rational& x);
		static const char sign{ '/' };
		int num_ = 0;
		int den_ = 1;
	private:
		int nod(const int& x, const int& y) {
			int a = std::max(std::abs(x), std::abs(y));
			int b = std::min(std::abs(x), std::abs(y));
			while (a != b) {
				a -= b;
				int temp = a;
				a = std::max(temp, b);
				b = std::min(temp, b);
			}
			return b;
		}
		Rational norm(int& x, int& y) {
			auto ans = nod(std::abs(x), std::abs(y));
			x /= ans;
			y /= ans;
			return Rational(x, y);
		}
};

Rational operator+(const Rational& x, const Rational& y);
Rational operator+(const Rational& x, const int& y);
Rational operator+(const int& x, const Rational& y);
Rational operator-(const Rational& x, const Rational& y);
Rational operator-(const Rational& x, const int& y);
Rational operator-(const int& x, const Rational& y);
Rational operator*(const Rational& x, const Rational& y);
Rational operator*(const Rational& x, const int& y);
Rational operator*(const int& x, const Rational& y);
Rational operator/(const Rational& x, const Rational& y);
Rational operator/(const Rational& x, const int& y);
Rational operator/(const int& x, const Rational& y);

inline std::istream& operator>>(std::istream& istrm, Rational& x) {
	return x.ReadFrom(istrm);
}

inline std::ostream& operator<<(std::ostream& ostrm, Rational& x) {
	return x.WriteTo(ostrm);
}

#endif