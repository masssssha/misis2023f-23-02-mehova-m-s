#include <iostream>

int main() {
	long n(0), m(0);
	std::cin >> n >> m;
	long num_pred(1), num(0);
	long long count(0);
	for (long i = 0; i < m; i++) {
		std::cin >> num;
		if (num_pred <= num) {
			count = count + num - num_pred;
		}
		else {
			count = count + n - num_pred + num;
		}
		num_pred = num;
	}
	std::cout << count;
}
