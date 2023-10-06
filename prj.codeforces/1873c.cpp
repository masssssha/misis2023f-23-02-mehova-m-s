#include <iostream>

int main()
{
    int t(0);
    std::cin >> t;
    for (int pu = 0; pu < t; pu++) {
        int count(0);
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                char temp;
                std::cin >> temp;
                if (temp != '.') {
                    if (i == 0 || i == 9) {
                        count += 1;
                    }
                    if (i == 1 || i == 8) {
                        if (j >= 1 && j <= 8) {
                            count += 2;
                        }
                        else {
                            count += 1;
                        }
                    }
                    if (i == 2 || i == 7) {
                        if (j >= 2 && j <= 7) {
                            count += 3;
                        }
                        if (j == 1 || j == 8) {
                            count += 2;
                        }
                        if (j == 0 || j == 9) {
                            count += 1;
                        }
                    }
                    if (i == 3 || i == 6) {
                        if (j >= 3 && j <= 6) {
                            count += 4;
                        }
                        if (j == 2 || j == 7) {
                            count += 3;
                        }
                        if (j == 1 || j == 8) {
                            count += 2;
                        }
                        if (j == 0 || j == 9) {
                            count += 1;
                        }
                    }
                    if (i == 4 || i == 5) {
                        if (j >= 4 && j <= 5) {
                            count += 5;
                        }
                        if (j == 3 || j == 6) {
                            count += 4;
                        }
                        if (j == 2 || j == 7) {
                            count += 3;
                        }
                        if (j == 1 || j == 8) {
                            count += 2;
                        }
                        if (j == 0 || j == 9) {
                            count += 1;
                        }
                    }
                }
            }
        }
        std::cout << count << std::endl;
    }
}
