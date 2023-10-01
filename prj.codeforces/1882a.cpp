#include <iostream>
#include <vector>

int main() {
	int t(0);
	std::cin >> t;
	for (int i = 0; i < t; i++) {
		int n(0);
		std::cin >> n;
		std::vector <int> a(n);
		for (int j = 0; j < n; j++) {
			std::cin >> a[j];
		}
		std::vector <int> b(n, 0);
		if (a[0] != 1) {
			b[0] = 1;
		}
		else {
			b[0] = 2;
		}
		for (int j = 1; j < n; j++) {
			if (a[j] != b[j - 1] + 1) {
				b[j] = b[j - 1] + 1;
			}
			else {
				b[j] = b[j - 1] + 2;
			}
		}
		std::cout << b[n - 1] << std::endl;
	}
}
