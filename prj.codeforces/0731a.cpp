#include <iostream>
#include <string>
#include <vector>
int main()
{
    std::string s;
    std::cin >> s;
    int now(0), count(0);
    for (auto i : s) {
        int first = std::abs(int('a') - int(i) - now);
        int second = 26 - std::abs(now - int('a') + int(i));
        count += std::min(first, second);
        now = int('a') - int(i);
    }
    std::cout << count;
    
}
