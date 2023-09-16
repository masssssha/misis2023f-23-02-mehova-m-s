#include <iostream>

int main() {
    int t = 0;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        int a(0), b(0); double c(0);
        std::cin >> a >> b >> c;
        if (a == b) {
            std::cout << 0 << std::endl;
        }
        else {
            int count = 1;
            double d = abs(a - b) / 2.0;
            while (d > c) {
                count += 1;
                d -= c;
            }
            std::cout << count << std::endl;
        }
    }
}
