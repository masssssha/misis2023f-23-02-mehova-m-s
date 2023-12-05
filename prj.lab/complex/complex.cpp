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
    if (x.re * x.re + x.im * x.im == 0) {
      throw std::invalid_argument("Zero denumenator in Complex");
    }
    re = (re1 * x.re + im1 * x.im) / (x.re * x.re + x.im * x.im);
    im = (im1 * x.re - re1 * x.im) / (x.re * x.re + x.im * x.im);
    return *this;
}

std::istream& Complex::ReadFrom(std::istream& istrm) {
  int f(0), s(0);
  char left, com, right;
  istrm >> left >> f >> com >> s >> right;
  if (istrm.good()) {
    if (left == '{' && com == ',' && right == '}') {
      re = f;
      im = s;
    }
    else {
      istrm.setstate(std::ios_base::failbit);
    }
  }
  return istrm;
}

std::ostream& Complex::WriteTo(std::ostream& ostrm) const {
    ostrm << leftBrace << re << separator << im << rightBrace;
    return ostrm;
}
