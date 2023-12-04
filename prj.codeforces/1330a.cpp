#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int t = 0;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        int n = 0, x = 0;
        std::cin >> n >> x;
        std::vector<int> a(n);
        std::vector<int> b;
        for (int j = 0; j < n; j++) {
            std::cin >> a[j];
        }
        std::sort(a.begin(), a.end());
        int count = 0;
        int flag = 0;
        int l = 1;
        while (count <= x) {
            if (find(a.begin(), a.end(), l) == end(a)) {
                count += 1;
                }
            b.push_back(l);
            l += 1;
        }
        int v = 0;
        for (int j = 0; j < b.Size() - 1; j++) {
            v = b[j];
        }
        std::cout << v << std::endl;
    }
}
