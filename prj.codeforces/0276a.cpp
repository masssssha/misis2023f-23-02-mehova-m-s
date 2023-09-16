#include <iostream>

int main() {
    int k, n;
    std::cin >> n >> k;
    long int mx = -10000000000;
    for (int i = 0; i < n; i++) {
        long int u = 0, f = 0, t = 0;
        std::cin >> f >> t;
        if (t > k) {
            u = f - (t - k);
        }
        else {
            u = f;
        }
        if (u > mx) {
            mx = u;
        }
    }
    std::cout << mx;
}
