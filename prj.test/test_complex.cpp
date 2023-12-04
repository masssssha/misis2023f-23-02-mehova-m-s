#include <iostream>
#include <sstream>
#include <complex/complex.hpp>

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
    std::cout << x << " / " << y << " = ";
    std::cout << (x / y) << std::endl;
    std::cout << y << " / " << z << " = ";
    std::cout << (y / z) << std::endl;
    std::cout << z << " / " << x << " = ";
    std::cout << (z / x) << std::endl;
}

int main()
{
    Complex x(1, 8);
    Complex y(0, -1);
    Complex g = -y;
    std::cout << g << std::endl;
    double z = 2.0;
    std::cout << "Addition test: " << std::endl;
    TestAdd(x, y, z);
    z = 5.0;
    std::cout << std::endl;
    std::cout << "Subtraction test: " << std::endl;
    TestSub(x, y, z);
    z = -3.0;
    std::cout << std::endl;
    std::cout << "Multiplication test: " << std::endl;
    TestMul(x, y, z);
    z = 1.0;
    std::cout << std::endl;
    std::cout << "Division test: " << std::endl;
    TestDiv(x, y, z);
}