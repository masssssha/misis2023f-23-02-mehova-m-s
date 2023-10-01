#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int t = 0;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        int n(0);
        std::string s;
        std::cin >> n >> s;
        int k = 0;
        std::cin >> k;
        std::vector<char> a(k);
        for (int j = 0; j < k; j++) {
            std::cin >> a[j];
        }
        for (int j = 0; j < n; j++) {
            if (std::find(a.begin(), a.end(), s[j]) != a.end()) {
                s[j] = '1';
            }
        }
        int mx(0), pu(0);
        for (int j = 0; j < n; j++) {
            if (s[j] == '1') {
                mx = std::max(mx, j - pu);
                pu = j;
            }
        }
        std::cout << mx << std::endl;
    }
}
