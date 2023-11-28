#include <iostream>
#include <sstream>
#include <complex/complex.hpp>

//Сложение двух комплексных, комплексное + вещественное
Complex operator+(const Complex& x, const Complex& y) {
    return Complex(x) += y;
}
Complex operator+(const Complex& x, const double& y) {
    return Complex(x) += Complex(y);
}
Complex operator+(const double& x, const Complex& y) {
    return Complex(x) += Complex(y);
}

//Вычитание двух комплексных, комплексное - вещественное
Complex operator-(const Complex& x, const Complex& y) {
    return Complex(x) -= y;
}
Complex operator-(const Complex& x, const double& y) {
    return Complex(x) -= Complex(y);
}
Complex operator-(const double& x, const Complex& y) {
    return Complex(x) -= Complex(y);
}

//Умножение двух комплексных, комплексное * вещественное
Complex operator*(const Complex& x, const Complex& y) {
    return Complex(x) *= y;
}
Complex operator*(const Complex& x, const double& y) {
    return Complex(x) *= Complex(y);
}
Complex operator*(const double& x, const Complex& y) {
    return Complex(x) *= Complex(y);
}

//Деление двух комплексных, комплексное / вещественное
Complex operator/(const Complex& x, const Complex& y) {
    return Complex(x) /= y;
}
Complex operator/(const Complex& x, const double& y) {
    return Complex(x) /= Complex(y);
}
Complex operator/(const double& x, const Complex& y) {
    return Complex(x) /= Complex(y);
}

Complex::Complex(const double real, const double imaginary) : re(real), im(imaginary) {}
Complex::Complex(const double real) : Complex(real, 0) {}

Complex& Complex::operator+=(const Complex& x) {
    re += x.re;
    im += x.im;
    return *this;
}

Complex& Complex::operator-=(const Complex& x) {
    re -= x.re;
    im -= x.im;
    return *this;
}
Complex& Complex::operator*=(const Complex& x) {
    double re1((*this).re);
    double im1((*this).im);
    re = re1 * x.re - im1 * x.im;
    im = re1 * x.im + im1 * x.re;
    return *this;
}
Complex& Complex::operator/=(const Complex& x) {
    double re1((*this).re);
    double im1((*this).im);
    re = (re1 * x.re + im1 * x.im) / (x.re * x.re + x.im * x.im);
    im = (im1 * x.re - re1 * x.im) / (x.re * x.re + x.im * x.im);
    return *this;
}

std::ostream& Complex::writeTo(std::ostream& ostrm) const {
    ostrm << leftBrace << re << separator << im << rightBrace;
    return ostrm;
}