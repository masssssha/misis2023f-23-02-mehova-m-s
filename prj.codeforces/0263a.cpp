#include <iostream>
#include <string>

int main() {
    int a[5][5];
    std::string s = "";
    int c1 = 0, c2 = 0;
    int flag = 0;
    for (int i = 0; i < 5; i++) {
        getline(std::cin, s);
        int count = 0;
        for (int j = 0; j < s.length(); j++) {
            if (s[j] == ' ') {
                count += 1;
            }
            if (s[j] == '1') {
                c1 = i;
                c2 = j - count;
            }
        }
    }
    int n1 = 2, n2 = 2;
    int total = abs(n1 - c1) + abs(n2 - c2);
    std::cout << total;
}
