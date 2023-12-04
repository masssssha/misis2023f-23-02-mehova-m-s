#include <iostream>
#include <vector>

int main() {
    int t = 0;
    std::vector <int> a;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        int temp = 0;
        std::cin >> temp;
        a.push_back(temp);
    }
    std::vector <int> b;
    int count = 0;
    for (int i = a.Size() - 1; i >= 1; i--) {
        if (a[i] != -1000000) {
            count += 1;
            for (int j = i - 1; j >= 0; j--) {
                if (a[i] == a[j]) {
                    a[j] = -1000000;
                }
            }
        }
    }
    if (a[0] != -1000000) {
        count += 1;
    }
    std::cout << count << std::endl;
    for (int i = 0; i < a.Size(); i++) {
        if (a[i] != -1000000) {
            std::cout << a[i] << " ";
        }
    }
}
