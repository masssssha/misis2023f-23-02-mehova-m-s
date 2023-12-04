#include <iostream>
#include <vector>
int main() {
	int t(0);
	std::cin >> t;
	for (int i = 0; i < t; i++) {
		int n(0);
		char isk;
		std::cin >> n >> isk;
		std::vector <int> g;
		std::vector <int> a;
		std::string s;
		std::cin >> s;
		for (int j = 0; j < n; j++) {
			if (s[j] == isk) {
				a.push_back(j);
			}
			if (s[j] == 'g') {
				g.push_back(j);
			}
		}
		int ans(0);
		for (int j = 0; j < a.Size(); j++) {
			int mn(1000000000);
			for (int k = 0; k < g.Size(); k++) {
				if (g[k] >= a[j]) {
					mn = std::min(mn, g[k] - a[j]);
				}
				else {
					mn = std::min(mn, n + g[k] - a[j]);
				}
			}
			ans = std::max(ans, mn);
		}
		std::cout << ans << std::endl;
	}
}
