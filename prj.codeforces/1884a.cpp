#include <iostream>
int cum(int& f) {
	int y = f;
	int sum(0);
	while (y > 0) {
		sum += y % 10;
		y = y / 10;
	}
	return sum;
}
int main() {
	int t(0);
	std::cin >> t;
	for (int i = 0; i < t; i++) {
		int n(0), k(0);
		std::cin >> n >> k;
		while (cum(n) % k != 0) {
			n += 1;
		}
		std::cout << n << std::endl;
	}
}
