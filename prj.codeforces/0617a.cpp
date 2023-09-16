#include <iostream>
 
int main() {
    int n = 0;
    std::cin >> n;
    int start = 0, count = 0;
    while (start < n) {
        start += 5;
        count++;
    }
    std::cout << count;
}
