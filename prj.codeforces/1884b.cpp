#include <iostream>
#include <vector>
int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int t(0);
	std::cin >> t;
	for (int i = 0; i < t; i++) {
		int n(0);
		std::cin >> n;
		std::string s;
		std::cin >> s;
		std::vector <int> a;
		for (int j = 0; j < n; j++) {
			if (s[j] == '0') {
				a.push_back(j);
			}
		}
		int len = a.size();
		long long count(0);
		int g(1);
		for (int j = 0; j < n; j++) {
			if (j >= len) {
				std::cout << -1 << " ";
			}
			else {
				count = count + n - g - a[len - 1 - j];
				g += 1;
				std::cout << count << " ";
			}
		}
		std::cout << std::endl;
	}
}
