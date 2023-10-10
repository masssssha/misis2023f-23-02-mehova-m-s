#include <iostream>   
#include <vector>

int main() {
    int t(0);
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        int n(0);
        std::cin >> n;
        std::vector<int> a(n);
        for (int j = 0; j < n; j++) {
            std::cin >> a[j];
        }
        int ans(a[0]);
        for (int j = 1; j < n; j++) {
            ans = ans & a[j];
        }
        std::cout << ans << std::endl;
    }
}
