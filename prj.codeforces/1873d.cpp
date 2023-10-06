#include <iostream>

int main() {
	int t(0);
	std::cin >> t;
	for (int i = 0; i < t; i++) {
		int n(0), k(0);
		std::cin >> n >> k;
		std::string s;
		std::cin >> s;
		int count(0), ans(0);
		int j = 0;
		while (j < n) {
			if (s[j] == 'B') {
				ans += 1;
				j += k;
			}
			else {
				j += 1;
			}
		}
		std::cout << ans << std::endl;
	}
}
