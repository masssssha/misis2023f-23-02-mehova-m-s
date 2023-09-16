#include <iostream>
#include <string>

int main() {
    int t = 0;
    std::cin >> t;
    std::string a;
    std::cin >> a;
    int count = 0;
    int total = 0;
    for (int i = 0; i < a.length(); i++) {
        if (a[i] == 'x') {
            count += 1;
        }
        else{
            count = 0;
        }
        if (count == 3) {
            total += 1;
            count -= 1;
        }
    }
    std::cout << total;
}
