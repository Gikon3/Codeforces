#include "Tree.h"

Tree::Tree()
{
    nodes_[1] = 1;
    nodes_[1].neighbours.push_back(nullptr);
}

void Tree::insert(std::pair<long long, long long> edge)
{
    auto it0 = nodes_.find(edge.first);
    auto it1 = nodes_.find(edge.second);

    if (it0 == nodes_.end())
        it0 = nodes_.emplace(edge.first, edge.first).first;
    if (it1 == nodes_.end())
        it1 = nodes_.emplace(edge.second, edge.second).first;

    Node* node0 = &it0->second;
    Node* node1 = &it1->second;

    node0->neighbours.push_back(node1);
    node1->neighbours.push_back(node0);
}

void Tree::calculate()
{
    Node* root = &nodes_[1];
    root->nLeaves = travel(nullptr, root);
}

long long Tree::nLeaves(long long node) const
{
    return nodes_.at(node).nLeaves;
}

long long Tree::travel(Node* parent, Node* node)
{
    if (node->neighbours.size() > 1) {
        for (Node* n : node->neighbours)
            if (n != parent)
                node->nLeaves += travel(node, n);
        return node->nLeaves;
    }

    node->nLeaves = 1;
    return node->nLeaves;
}
