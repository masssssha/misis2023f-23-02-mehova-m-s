#include <iostream>
#include <vector>
int main()
{
    int t(0);
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        int n(0), k(0), x(0);
        std::cin >> n >> k >> x;
        std::vector <int> a(n);
        int temp(0), index(0), sum(0);
        while (temp < k && index < n) {
            a[index] = temp;
            sum += temp;
            index += 1;
            temp += 1;
        }
        if (a[index - 1] != k - 1) {
            std::cout << -1 << std::endl;
        }
        else {
            if (a[index - 1] > x) {
                std::cout << -1 << std::endl;
            }
            else {
                for (int j = index; j < n; j++) {
                    if (x != k) {
                        sum += x;
                    }
                    else {
                        sum += (x - 1);
                    }
                }
                std::cout << sum << std::endl;
            }
        }
    }
}
