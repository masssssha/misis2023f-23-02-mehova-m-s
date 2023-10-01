//ограничение по времени
#include <iostream>
#include <string>
#include <vector>

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
        std::vector<char> ans;
        for (int j = n - 1; j >= 0; j--) {
            if (std::find(a.begin(), a.end(), s[j]) == a.end()) {
                ans.push_back(s[j]);
            }
            else {
                ans.push_back(s[j]);
                break;
            }
        }
        std::string pupu;
        for (int j = ans.size() - 1; j >= 0; j--) {
            pupu += ans[j];
        }
        int count(0), count_prob(0);
        for (int j = 0; j < s.size(); j++) {
            if (std::find(a.begin(), a.end(), s[j]) != a.end()) {
                s[j] = '1';
            }
        }
        while (pupu.size() != s.size() - count_prob) {
            int flag = 0;
            for (int j = 0; j < s.size() - 1; j++) {
                if ((s[j + 1] == '1' || s[j + 1] == '_') && (s[j] != '_')) {
                    s[j] = '_';
                    count_prob += 1;
                    flag = 1;
                }
            }
            if (flag == 1) {
                count += 1;
            }
        }
        std::cout << count << std::endl;
    }
}
