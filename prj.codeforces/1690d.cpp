#include <iostream>
#include <vector>
int main() {
	int t(0);
	std::cin >> t;
	for (int i = 0; i < t; i++) {
		int n(0), k(0);
		std::cin >> n >> k;
		std::vector <int> a;
		std::string s;
		std::cin >> s;
		int count_w = 0;
		int mn(100000000);
		for (int j = 0; j < k; j++) {
			if (s[j] == 'W') {
				count_w += 1;
			}
		}
		mn = std::min(mn, count_w);
		for (int j = 1; j < n - k + 1; j++) {
			if (s[j - 1] == 'W') {
				count_w -= 1;
			}
			if (s[j + k - 1] == 'W') {
				count_w += 1;
			}
			if (count_w >= 0 && count_w < mn) {
				mn = count_w;
			}
		}
		std::cout << mn << std::endl;
	}
}
