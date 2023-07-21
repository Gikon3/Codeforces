#include <iostream>
#include <algorithm>
#include <list>
#include "Tree.h"

void test(std::list<long long>& answer)
{
    long long nPeaks = 0;
    std::cin >> nPeaks;

    Tree tree;
    for (long long i = 0; i < nPeaks - 1; ++i) {
        std::pair<long long, long long> node;
        std::cin >> node.first >> node.second;
        tree.insert(node);
    }

    tree.calculate();

    long long nHypotheses = 0;
    std::cin >> nHypotheses;
    for (long long i = 0; i < nHypotheses; ++i) {
        std::pair<long long, long long> apples = { 0, 0 };
        std::cin >> apples.first >> apples.second;
        answer.push_back(tree.nLeaves(apples.first) * tree.nLeaves(apples.second));
    }
}

int main()
{
    long long nTests = 0;
    std::cin >> nTests;

    std::list<long long> answer;
    for (long long i = 0; i < nTests; ++i)
        test(answer);

    for (auto v : answer)
        std::cout << v << std::endl;

    return 0;
}