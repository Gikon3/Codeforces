#include <iostream>

int main()
{
    int w = 0;
    int h = 0;
    std::cin >> w >> h;

    int degree = w + h;
    unsigned long long answer = 1;
    while (degree > 0) {
        const int sh = std::min(degree, 32);
        degree -= sh;
        answer <<= sh;
        answer %= 998244353;
    }

    std::cout << answer << std::endl;
}

