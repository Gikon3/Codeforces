#include <iostream>

long long sumInTree(long long num)
{
    long long sum = 0;
    while (num > 1) {
        sum += num;
        num /= 2;
    }
    sum += num;
    return sum;
}

int main()
{
    int nTests = 0;
    std::cin >> nTests;

    for (int i = 0; i < nTests; ++i) {
        long long num = 0;
        std::cin >> num;
        std::cout << sumInTree(num) << std::endl;
    }

    return 0;
}