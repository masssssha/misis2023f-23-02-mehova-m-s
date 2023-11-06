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
    bool operator!=(const Complex & x) const { return !operator==(x); }
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

Complex operator+(const Complex& x, const Complex& y) {
    return Complex(x) += y;
}
Complex operator-(const Complex& lhs, const Complex& rhs) {
    return Complex(lhs) -= rhs;
}
Complex operator*(const Complex& x, const Complex& y) {
    return Complex(x) *= y;
}
Complex operator/(const Complex& x, const Complex& y) {
    return Complex(x) /= y;
}

int main()
{
    Complex z(1, 8);
    Complex y(2, 3);
    std::cout << "First complex number: " << z << std::endl;
    std::cout << "Second complex number: " << y << std::endl;
    Complex w = z;
    std::cout << "Third complex number = first: " << w << " = " << z << std::endl;
    std::cout << z << " += " << w << ": ";
    z += w;
    std::cout << z << std::endl;
    std::cout << y << " -= " << z << ": ";
    y -= z;
    std::cout << y << std::endl;
    std::cout << w << " *= " << z << ": ";
    w *= z;
    std::cout << w << std::endl;
    std::cout << w << " /= " << z << ": ";
    w /= z;
    std::cout << z << std::endl;
    std::cout << Complex(8, 0) << " + " << y << " = " << (Complex(8, 0) + y) << std::endl;
    std::cout << Complex(8, 0) << " - " << w << " = " << (Complex(8, 0) - w) << std::endl;
    std::cout << Complex(8, 0) << " * " << y << " = " << (Complex(8, 0) * y) << std::endl;
    std::cout << Complex(8, 0) << " / " << Complex(1, 0) << " = " << (Complex(8, 0) / Complex(1, 0)) << std::endl;
    std::cout << z << " + " << 3 << " = " << (z + Complex(3)) << std::endl;
    std::cout << y << " - " << 2.1 << " = " << (y - Complex(2.1)) << std::endl;
    std::cout << w << " * " << 4 << " = " << (w * Complex(4)) << std::endl;
    std::cout << z << " / " << 5 << " = " << (z / Complex(5)) << std::endl;
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
