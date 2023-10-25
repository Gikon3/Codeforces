#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

int countNumberFines(const std::vector<int>& in, const std::vector<int>& out)
{
    std::set<int> overtake;
    for (auto itIn = in.begin(), itOut = out.begin(); itOut != out.end(); ) {
        if (overtake.count(*itIn) == 1) {
            ++itIn;
        }
        else if (*itIn != *itOut) {
            overtake.insert(*itOut);
            ++itOut;
        }
        else {
            ++itIn;
            ++itOut;
        }
    }

    return overtake.size();
}

int main()
{
    int nCars = 0;
    std::cin >> nCars;
    std::vector<int> in(nCars);
    std::vector<int> out(nCars);

    for (auto& e : in)
        std::cin >> e;
    for (auto& e : out)
        std::cin >> e;

    const int nFines = countNumberFines(in, out);
    std::cout << nFines << std::endl;

    return 0;
}
