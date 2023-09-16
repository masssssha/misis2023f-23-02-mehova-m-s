#include <iostream>

int main() {
    int n = 0;
    std::cin >> n;
    int god = ++n, flag = 0;
    while (flag == 0) {
        int first = god % 10;
        int sec = (god / 10) % 10;
        int th = (god / 100) % 10;
        int fort = (god / 1000);
        if ((first != sec) && (first != th) && (first != fort) && (sec != th) && (sec != fort) && (th != fort)) {
            flag = 1;
            std::cout << god;
            break;
        }
        god++;
    }
}
