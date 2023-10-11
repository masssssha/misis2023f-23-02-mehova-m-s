#include <iostream>

int main() {
	int t(0);
	std::cin >> t;
	for (int i = 0; i < t; i++) {
		int n(0);
		std::cin >> n;
		int x(0), y(0), z(0);
		if (n % 3 == 0) {
			x = 1;
			y = 4;
			z = n - x - y;
		}
		else if (n % 3 == 1) {
			x = 1;
			y = 2;
			z = n - x - y;
		}
		else {
			x = 1;
			y = 2;
			z = n - x - y;
		}
		if ((z > 0) && (z != x) && (z != y)) {
			std::cout << "YES" << std::endl;
			std::cout << x << " " << y << " " << z << std::endl;
		}
		else {
			std::cout << "NO" << std::endl;
		}
	}
}
