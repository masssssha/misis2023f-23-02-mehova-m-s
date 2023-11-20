#include <iostream>
#include <sstream>
#include <rational/rational.hpp>

int main() {
	Rational z(-3, 4);
	Rational z2 = z;
	Rational x(5, 1);
	std::cout << z << " ";
	if (z >= z2) {
		std::cout << ">= " << z2 << std::endl;
	}
	else {
		std::cout << "< " << z2 << std::endl;
	}
	std::cout << z << " ";
	if (z > x) {
		std::cout << "> " << x << std::endl;
	}
	else {
		std::cout << "<= " << x << std::endl;
	}
	std::cout << z;
	z += Rational(2, 4);
	std::cout << " += " << Rational(2, 4) << " : " << z << std::endl;
	std::cout << z << " -= ";
	z -= Rational(1, 2);
	std::cout << Rational(1, 2) << " : " << z << std::endl;
	std::cout << z << " *= ";
	z *= Rational(1, 2);
	std::cout << Rational(1, 2) << " : " << z << std::endl;
	std::cout << z << " /= ";
	z /= Rational(1, 2);
	std::cout << Rational(1, 2) << " : " << z << std::endl;
	std::cout << z << " + " << x << " = " << (z + x) << std::endl;
	std::cout << z << " + " << 7 << " = " << (z + 7) << std::endl;
	std::cout << 4 << " + " << x << " = " << (4 + x) << std::endl;
	std::cout << x << " - " << z << " = " << (x - z) << std::endl;
	std::cout << z << " - " << 2 << " = " << (z - 2) << std::endl;
	std::cout << 1 << " - " << x << " = " << (1 - x) << std::endl;
	std::cout << x << " * " << z << " = " << (x * z) << std::endl;
	std::cout << z << " * " << 3 << " = " << (z * 3) << std::endl;
	std::cout << 2 << " * " << x << " = " << (2 * x) << std::endl;
	std::cout << x << " / " << z << " = " << (x / z) << std::endl;
	std::cout << z << " / " << 1 << " = " << (z / 1) << std::endl;
	std::cout << 2 << " / " << x << " = " << (2 / x) << std::endl;
}
