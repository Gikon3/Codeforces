#include <iostream>
#include <vector>
#include <cmath>

struct Result
{
    std::vector<int> circle;
    bool equal;
};

Result almostEual(int n)
{
    Result retval{std::vector<int>(n * 2), false};
    const int halfSize = retval.circle.size() / 2;

    bool select = false;
    int sum[] = {0, 0};
    for (int i = 0; i < halfSize; ++i) {
        const int val = i * 2 + 1;
        if (!select) {
            sum[0] += val;
            sum[1] += val + 1;
            retval.circle[i] = val;
            retval.circle[i + halfSize] = val + 1;
        }
        else {
            sum[0] += val + 1;
            sum[1] += val;
            retval.circle[i] = val + 1;
            retval.circle[i + halfSize] = val;
        }
        select = !select;
    }

    retval.equal = std::abs(sum[0] - sum[1]) == 1;
    return retval;
}

int main()
{
    int n = 0;
    std::cin >> n;

    const Result result = almostEual(n);
    if (result.equal) {
        std::cout << "YES" << std::endl;
        for (const int e : result.circle)
            std::cout << e << ' ';
        std::cout << std::endl;
    }
    else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}