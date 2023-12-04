#ifndef RATIONAL_HPP
#define RATIONAL_HPP

#include <iosfwd>
#include <sstream>

class Rational {
	public:
		Rational() = default;
		~Rational() = default;
		Rational(const Rational& x) = default;
		Rational(const int64_t& first, const int64_t& second);
		Rational(const int64_t& first);
		Rational& operator=(const Rational&) = default;

		std::int64_t num() const noexcept { return num_; }
		std::int64_t den() const noexcept { return den_; }

		std::istream& ReadFrom(std::istream& istrm);
		std::ostream& WriteTo(std::ostream& ostrm) const;
		bool operator==(const Rational& x) const { return num_ * x.den_ - x.num_ * den_ == 0; }
		bool operator!=(const Rational& x) const { return !operator==(x); }
		bool operator>(const Rational& x) const { return num_ * x.den_ - x.num_ * den_ > 0; }
		bool operator<(const Rational& x) const { return num_ * x.den_ - x.num_ * den_ < 0; }
		bool operator>=(const Rational& x) const { return num_ * x.den_ - x.num_ * den_ >= 0; }
		bool operator<=(const Rational& x) const { return num_ * x.den_ - x.num_ * den_ <= 0; }
		Rational& operator+=(const Rational& x);
		Rational& operator-=(const Rational& x);
		Rational& operator*=(const Rational& x);
		Rational& operator/=(const Rational& x);
		static const char sign{ '/' };
		int64_t num_ = 0;
		int64_t den_ = 1;
	private:
		int64_t nod(const int64_t& x, const int64_t& y) {
			int64_t a = std::max(std::abs(x), std::abs(y));
			int64_t b = std::min(std::abs(x), std::abs(y));
			while (a != b) {
				a -= b;
				int64_t temp = a;
				a = std::max(temp, b);
				b = std::min(temp, b);
			}
			return b;
		}
		void norm() {
			auto ans = nod(std::abs(num_), std::abs(den_));
			if (den_ < 0) {
				num_ *= (-1);
				den_ *= (-1);
			}
			num_ /= ans;
			den_ /= ans;
		}
};

Rational operator+(const Rational& x, const Rational& y);
Rational operator+(const Rational& x, const int64_t& y);
Rational operator+(const int64_t& x, const Rational& y);
Rational operator-(const Rational& x, const Rational& y);
Rational operator-(const Rational& x, const int64_t& y);
Rational operator-(const int64_t& x, const Rational& y);
Rational operator*(const Rational& x, const Rational& y);
Rational operator*(const Rational& x, const int64_t& y);
Rational operator*(const int64_t& x, const Rational& y);
Rational operator/(const Rational& x, const Rational& y);
Rational operator/(const Rational& x, const int64_t& y);
Rational operator/(const int64_t& x, const Rational& y);

inline std::istream& operator>>(std::istream& istrm, Rational& x) {
	return x.ReadFrom(istrm);
}

inline std::ostream& operator<<(std::ostream& ostrm, Rational& x) {
	return x.WriteTo(ostrm);
}

#endif
