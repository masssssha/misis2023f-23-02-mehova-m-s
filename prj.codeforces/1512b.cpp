#include <iostream>
int main()
{
    int t(0);
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        int n(0);
        std::cin >> n;
        int a1(0), b1(0), a2(0), b2(0), a3(0), b3(0), a4(0), b4(0), flag(0);
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                char temp;
                std::cin >> temp;
                if (temp == '*') {
                    if (flag == 0) {
                        a1 = j;
                        b1 = k;
                        a3 = a1;
                        b4 = b1;
                        flag = 1;
                    }
                    else {
                        a2 = j;
                        b2 = k;
                        a4 = a2;
                        b3 = b2;
                    }
                }
            }
        }
        if (a1 == a2) {
            if (a1 != 0) {
                a3 = 0;
                a4 = 0;
            }
            else {
                a3 = 1;
                a4 = 1;
            }
        }
        if (b1 == b2) {
            if (b1 != 0) {
                b3 = 0;
                b4 = 0;
            }
            else {
                b3 = 1;
                b4 = 1;
            }
        }
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if ((j == a1 && k == b1) || (j == a2 && k == b2) || (j == a3 && k == b3) || (j == a4 && k == b4)) {
                    std::cout << "*";
                }
                else {
                    std::cout << ".";
                }
            }
            std::cout << std::endl;
        }
    }
    
}
