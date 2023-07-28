#include <iostream>
#include <vector>
#include <cmath>

struct Result
{
    int nOperations;
    long long sum;
};

Result countOperations(const std::vector<int>& data)
{
    Result res = {0, std::abs(data[0])};
    bool fl = data[0] >= 0;
    for (int i = 1; i < data.size(); ++i) {
        res.sum += std::abs(data[i]);
        if (!fl && data[i] > 0) {
            fl = true;
            ++res.nOperations;
        }
        else if (fl && data[i] < 0) {
            fl = false;
        }
    }

    res.nOperations += static_cast<long long>(!fl);

    return res;
}

int main()
{
    int nTests = 0;
    std::cin >> nTests;

    for (int i = 0; i < nTests; ++i) {
        int size = 0;
        std::cin >> size;
        std::vector<int> data(size);
        for (auto& e : data)
            std::cin >> e;
        const Result res = countOperations(data);
        std::cout << res.sum << ' ' << res.nOperations << std::endl;
    }

    return 0;
}