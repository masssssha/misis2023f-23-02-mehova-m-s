#include <iostream>

int main() {
    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        int n = 0, count = 0, st = 0;
        std::cin >> n;
        int r = n;
        while (r > 0) {
            if (r % 10 != 0) {
                count += 1;
            }
            r /= 10;
        }
        std::cout << count << std::endl;
        while (n > 0) {
            if (n % 10 != 0) {
                int temp = n % 10;
                for (int k = 0; k < st; k++) {
                    temp *= 10;
                }
                std::cout << temp << " ";
            }
            st += 1;
            n /= 10;
        }
        std::cout << std::endl;
    }
}
