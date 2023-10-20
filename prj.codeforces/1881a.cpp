#include <iostream>
#include <string>
int main()
{
	int t(0);
	std::cin >> t;
	for (int i = 0; i < t; i++) {
		int n(0), m(0);
		std::cin >> n >> m;
		std::string s;
		std::cin >> s;
		std::string x;
		std::cin >> x;
		int count(0);
		while (n < m) {
			s += s;
			count += 1;
			n += n;
		}
		if (s.find(x) != std::string::npos) {
			std::cout << count << std::endl;
		}
		else {
			s += s;
			count += 1;
			if (s.find(x) != std::string::npos) {
				std::cout << count << std::endl;
			}
			else {
				std::cout << -1 << std::endl;
			}
		}
	}
}
