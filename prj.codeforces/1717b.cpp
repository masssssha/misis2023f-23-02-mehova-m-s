#include <iostream>
#include <vector>
int main() {
    int t = 0;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        int n(0), k(0), r(0), c(0);
        std::cin >> n >> k >> r >> c;
        std::vector<std::vector<int>> a(3*n, std::vector<int>(3*n));
        for (int i = 0; i < 3*n; i++) {
            for (int j = 0; j < 3*n; j++) {
                if (i % k == (r - 1) % k && j % k == (c - 1) % k) {
                    a[i][j] = 2;
                }
                else {
                    a[i][j] = 1;
                }
            }
        }
        for (int i = 0; i < 2 * n; i++) {
            for (int j = 0; j < 2 * n; j++) {
                if (a[i][j] == 2) {
                    for (int e = i; e < i + k; e++) {
                        for (int f = j; f < j + k; f++) {
                            if (e - i == f - j) {
                                a[e][f] = 2;
                            }
                        }
                    }
                }
            }
        }
        for (int i = n; i < 2*n; i++) {
            for (int j = n; j < 2*n; j++) {
                if (a[i][j] == 2) {
                    std::cout << "X";
                }
                else {
                    std::cout << ".";
                }
            }
            std::cout << std::endl;
        }
    }
}
