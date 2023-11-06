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

void TestAdd(Complex x, Complex y, double z) {
    std::cout << x << " += " << y << ": ";
    x += y;
    std::cout << x << std::endl;
    std::cout << x << " + " << y << " = " << (x + y) << std::endl;
    std::cout << y << " + " << z << " = " << (y + z) << std::endl;
    std::cout << z << " + " << x << " = " << (z + x) << std::endl;
}

void TestSub(Complex x, Complex y, double z) {
    std::cout << x << " -= " << y << ": ";
    x -= y;
    std::cout << x << std::endl;
    std::cout << x << " - " << y << " = " << (x - y) << std::endl;
    std::cout << y << " - " << z << " = " << (y - z) << std::endl;
    std::cout << z << " - " << x << " = " << (z - x) << std::endl;
}

void TestMul(Complex x, Complex y, double z) {
    std::cout << x << " *= " << y << ": ";
    x *= y;
    std::cout << x << std::endl;
    std::cout << x << " * " << y << " = " << (x * y) << std::endl;
    std::cout << y << " * " << z << " = " << (y * z) << std::endl;
    std::cout << z << " * " << x << " = " << (z * x) << std::endl;
}

void TestDiv(Complex x, Complex y, double z) {
    std::cout << x << " /= " << y << ": ";
    x /= y;
    std::cout << x << std::endl;
    std::cout << x << " / " << y << " = " << (x / y) << std::endl;
    std::cout << y << " / " << z << " = " << (y / z) << std::endl;
    std::cout << z << " / " << x << " = " << (z / x) << std::endl;
}

int main()
{
    Complex x(1, 8);
    Complex y(2, 3);
    double z = 2;
    std::cout << "Addition test: " << std::endl;
    TestAdd(x, y, z);
    z = 5;
    std::cout << std::endl;
    std::cout << "Subtraction test: " << std::endl;
    TestSub(x, y, z);
    z = -3;
    std::cout << std::endl;
    std::cout << "Multiplication test: " << std::endl;
    TestMul(x, y, z);
    std::cout << std::endl;
    std::cout << "Division test: " << std::endl;
    TestDiv(x, y, z);
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
