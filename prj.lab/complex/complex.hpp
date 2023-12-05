#ifndef COMPLEX_HPP
#define COMPLEX_HPP
#include <iostream>
#include <sstream>

struct Complex {
    double re{ 0.0 };
    double im{ 0.0 };
    Complex(const double real, const double imaginary);
    explicit Complex(const double real);
    Complex() = default;
    ~Complex() = default;
    bool operator==(const Complex& x) const { 
      return ((re - x.re <= 2 * std::numeric_limits<double>::epsilon()) && (im - x.im <= 2 * std::numeric_limits<double>::epsilon()));
    }
    bool operator!=(const Complex& x) const { return !operator==(x); }
    Complex& operator=(const Complex&) = default;
    Complex& operator+=(const Complex& x);
    Complex& operator-=(const Complex& x);
    Complex& operator*=(const Complex& x);
    Complex& operator/=(const Complex& x);
    Complex operator-() const noexcept {
      if (im != 0 && re != 0) {
        return Complex(-re, -im);
      }
      else {
        if (im == 0 && re != 0) {
          return Complex(-re, im);
        }
        if (re == 0 && im != 0) {
          return Complex(re, -im);
        }
        if (re == 0 && im == 0) {
          return Complex(re, im);
        }
      }
    }
    std::ostream& WriteTo(std::ostream& ostrm) const;
    std::istream& ReadFrom(std::istream& istrm);
    static const char leftBrace{ '{' };
    static const char separator{ ',' };
    static const char rightBrace{ '}' };
};
inline std::istream& operator>>(std::istream& istrm, Complex& x) {
  return x.ReadFrom(istrm);
}
inline std::ostream& operator<<(std::ostream& ostrm, const Complex& rhs) {
    return rhs.WriteTo(ostrm);
}
Complex operator+(const Complex& x, const Complex& y);
Complex operator+(const Complex& x, const double& y);
Complex operator+(const double& x, const Complex& y);
Complex operator-(const Complex& x, const Complex& y);
Complex operator-(const Complex& x, const double& y);
Complex operator-(const double& x, const Complex& y);
Complex operator*(const Complex& x, const Complex& y);
Complex operator*(const Complex& x, const double& y);
Complex operator*(const double& x, const Complex& y);
Complex operator/(const Complex& x, const Complex& y);
Complex operator/(const Complex& x, const double& y);
Complex operator/(const double& x, const Complex& y);

#endif