#include <iostream>

int main()
{
    int t = 0;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        int n(0), m(0), x(0), y(0), d(0);
        std::cin >> n >> m >> x >> y >> d;
        if ((x - 1 <= d || m - y <= d) && (n - x <= d || y - 1 <= d)) {
            std::cout << -1 << std::endl;
        }
        else {
            std::cout << n + m - 2 << std::endl;
        }
    }
}
