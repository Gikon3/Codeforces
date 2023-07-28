#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

#define TESTS 0

int evenFix(std::vector<int>& elems)
{
    std::set<int> odd;
    for (auto e : elems) {
        while (e % 2 == 0 && odd.count(e) == 0) {
            odd.insert(e);
            e /= 2;
        }
    }
    return odd.size();
}

void test(std::vector<int>& v, int answer)
{
    for (auto e : v)
        std::cout << e << " ";
    std::cout << std::endl;
    const int myAnswer = evenFix(v);
    std::cout << answer << (answer == myAnswer ? " == " : " != ") << myAnswer << std::endl;
    std::cout << std::endl;
}

int main()
{
#if TESTS == 0
    int nTests = 0;
    std::cin >> nTests;
    for (int i = 0; i < nTests; ++i) {
        int nElements = 0;
        int element = 0;
        std::cin >> nElements;
        std::vector<int> elements(nElements);
        for (int j = 0; j < nElements; ++j) {
            std::cin >> element;
            elements[j] = element;
        }
        std::cout << evenFix(elements) << std::endl;
    }
#else
    std::vector<int> v0 = { 1, 1, 1, 2 };
    test(v0, 1);

    std::vector<int> v1 = { 2, 4, 6, 8 };
    test(v1, 4);

    std::vector<int> v2 = { 250, 36, 100, 32, 1, 3, 4, 8, 6, 300, 100 };
    test(v2, 13);

    std::vector<int> v3 = { 7, 9, 11, 3, 1, 1, 13, 1, 5 };
    test(v3, 0);
#endif

    return 0;
}
