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
    bool operator==(const Complex& x) const { return (re == x.re) && (im == x.im); }
    bool operator!=(const Complex& x) const { return !operator==(x); }
    Complex& operator=(const Complex&) = default;
    Complex& operator+=(const Complex& x);
    Complex& operator-=(const Complex& x);
    Complex& operator*=(const Complex& x);
    Complex& operator/=(const Complex& x);
    std::ostream& writeTo(std::ostream& ostrm) const;
    static const char leftBrace{ '{' };
    static const char separator{ ',' };
    static const char rightBrace{ '}' };
};
inline std::ostream& operator<<(std::ostream& ostrm, const Complex& rhs) {
    return rhs.writeTo(ostrm);
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