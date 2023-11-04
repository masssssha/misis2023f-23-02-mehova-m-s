#include <iostream>

struct Complex {
    double re{ 0.0 };
    double im{ 0.0 };
    Complex(double real, double imaginary) {
        re = real;
        im = imaginary;
    }
    void print() {
        std::cout << "{" << re << "," << im << "}" << std::endl;
    }
    bool operator==(const Complex& x) const { 
        return (re == x.re) && (im == x.im); 
    }
    bool operator!=(const Complex & x) const { 
        return !operator==(x); 
    }
    Complex& operator+=(const Complex& x) {
        re += x.re;
        im += x.im;
        return *this;
    }
    Complex& operator-=(const Complex& x) {
        re -= x.re;
        im -= x.im;
        return *this;
    }
    Complex& operator*=(const Complex& x) {
        double re1(this->re);
        double im1(this->im);
        this->re = re1 * x.re - im1 * x.im;
        this->im = re1 * x.im + im1 * x.re;
        return *this;
    }
    Complex& operator/=(const Complex& x) {
        double re1(this->re);
        double im1(this->im);
        this->re = (re1 * x.re + im1 * x.im) / (x.re * x.re + x.im * x.im);
        this->im = (im1 * x.re - re1 * x.im) / (x.re * x.re + x.im * x.im);
        return *this;
    }
};
Complex operator+(const Complex& x, const Complex& y) {
    Complex sum(x);
    sum += y;
    std::cout << "ADDITION: ";
    return sum;
}
Complex operator-(const Complex& x, const Complex& y) {
    Complex sum(x);
    sum -= y;
    std::cout << "SUBTRACTION: ";
    return sum;
}
Complex operator*(const Complex& x, const Complex& y) {
    Complex total(x);
    total *= y;
    std::cout << "MULTIPLICATION: ";
    return total;
}
Complex operator/(const Complex& x, const Complex& y) {
    Complex total(x);
    total /= y;
    std::cout << "DIVISION: ";
    return total;
}

int main()
{
    std::cout << "Enter 4 numbers: " << std::endl;
    double first(0), second(0), f(0), s(0);
    std::cin >> first >> second >> f >> s;
    Complex z(first, second);
    Complex y(f, s);
    std::cout << "First complex number: ";
    z.print();
    std::cout << "Second complex number: ";
    y.print();
    Complex sum = z + y;
    sum.print();
    Complex minus = z - y;
    minus.print();
    Complex mul = z * y;
    mul.print();
    if (y.re == 0 && y.im == 0) {
        std::cout << "ERROR DIVISION";
    }
    else {
        Complex div = z / y;
        div.print();
    }
}
