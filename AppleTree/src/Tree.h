#pragma once

#include <algorithm>
#include <vector>
#include <map>

class Tree final
{
public:
    Tree();
    void insert(std::pair<long long, long long> edge);
    void calculate();
    long long nLeaves(long long node) const;

private:
    struct Node
    {
        Node() : id(0) {}
        Node(long long id) : id(id) {}
        std::vector<Node*> neighbours;
        long long id;
        long long nLeaves = 0;
    };

private:
    long long travel(Node* parent, Node* node);

private:
    std::map<long long, Node> nodes_;
};
