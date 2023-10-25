#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <stack>

//#define GRAPH_MEM
//#define GRAPH_FAST
#define DSU

#if defined(GRAPH_MEM)
class Graph
{
    struct Node
    {
        std::vector<int> neighbours;
    };

    struct Store
    {
        int node;
        int prev;
        int no;
        bool prevFl;
    };

public:
    Graph(int max) :
        max_(max)
    {
    }

    void add(int a, int b)
    {
        Node* n0 = &graph[a];
        Node* n1 = &graph[b];
        n0->neighbours.push_back(b);
        n1->neighbours.push_back(a);
        unused_.insert(a);
        unused_.insert(b);
    }

    int calculate()
    {
        std::vector<bool> view(max_ + 1);
        std::stack<Store> stack;
        int count = 0;
        bool last = false;

        stack.push({graph.begin()->first, 0, 0, false});

        while (!unused_.empty() || !last) {
            last = unused_.empty();

            while (!stack.empty()) {
                Store store = stack.top();
                stack.pop();
                view[store.node] = true;
                unused_.erase(store.node);

                for (; store.no < graph[store.node].neighbours.size(); ++store.no) {
                    if (store.prev != graph[store.node].neighbours[store.no] && !view[graph[store.node].neighbours[store.no]]) {
                        stack.push({store.node, store.prev, store.no + 1, store.prevFl});
                        stack.push({graph[store.node].neighbours[store.no], store.node, 0, false});
                        break;
                    }
                    else if (store.prev == graph[store.node].neighbours[store.no] && !store.prevFl) {
                        store.prevFl = true;
                    }
                    else {
                        ++count;
                    }
                }
            }

            if (!unused_.empty()) {
                const int node = *unused_.begin();
                unused_.erase(node);
                if (!view[node])
                    stack.push({node, 0, 0, false});
            }
        }

        return count / 2;
    }

    void dump(std::ostream& os) const
    {
        for (const auto& [key, nodes] : graph) {
            std::cout << key << std::endl;
            for (const auto& n : nodes.neighbours)
                std::cout << "  " << n << std::endl;
        }
    }

private:
    std::map<int, Node> graph;
    std::set<int> unused_;
    int max_;
};

#elif defined(GRAPH_FAST)
class Graph
{
    struct Node
    {
        std::vector<Node*> neighbours;
    };

    struct Store
    {
        Node* node;
        Node* prev;
        std::vector<Node*>::iterator it;
        bool prevFl;
    };

public:
    void add(int a, int b)
    {
        Node* n0 = &graph[a];
        Node* n1 = &graph[b];
        n0->neighbours.push_back(n1);
        n1->neighbours.push_back(n0);
        unused_.insert(n0);
        unused_.insert(n1);
    }

    int calculate()
    {
        std::set<Node*> view;
        std::stack<Store> stack;
        int count = 0;
        bool last = false;

        stack.push({&graph.begin()->second, nullptr, graph.begin()->second.neighbours.begin(), false});

        while (!unused_.empty() || !last) {
            last = unused_.empty();

            while (!stack.empty()) {
                Store store = stack.top();
                stack.pop();
                view.insert(store.node);
                unused_.erase(store.node);

                for (; store.it != store.node->neighbours.end(); ++store.it) {
                    if (*store.it != store.prev && !view.contains(*store.it)) {
                        stack.push({store.node, store.prev, store.it + 1, store.prevFl});
                        stack.push({*store.it, store.node, (*store.it)->neighbours.begin(), false});
                        break;
                    }
                    else if (*store.it == store.prev && !store.prevFl) {
                        store.prevFl = true;
                    }
                    else {
                        ++count;
                    }
                }
            }

            if (!unused_.empty()) {
                Node* node = *unused_.begin();
                unused_.erase(node);
                if (!view.contains(node))
                    stack.push({node, nullptr, node->neighbours.begin(), false});
            }
        }

        return count / 2;
    }

    void dump(std::ostream& os) const
    {
        for (const auto& [key, nodes] : graph) {
            std::cout << key << std::endl;
            for (const auto& n : nodes.neighbours)
                std::cout << "  " << n << std::endl;
        }
    }

private:
    std::map<int, Node> graph;
    std::set<Node*> unused_;
};
#endif

#if defined(GRAPH_MEM) || defined(GRAPH_FAST)
int main()
{
    int nGuests = 0;
    int nSnacks = 0;
    std::cin >> nSnacks >> nGuests;

#if defined(GRAPH_FAST)
    Graph graph;
#elif defined(GRAPH_MEM)
    Graph graph{nSnacks};
#endif
    for (int i = 0; i < nGuests; ++i) {
        int a = 0;
        int b = 0;
        std::cin >> a >> b;
        graph.add(a, b);
    }

    std::cout << graph.calculate();
}
#endif

#if defined(DSU)
class Dsu
{
public:
    Dsu(int size) :
        tree_(size), rank_(size)
    {
        for (int i = 0; i < tree_.size(); ++i)
            tree_[i] = i;
    }

    int root(int val)
    {
        if (val == tree_[val])
            return val;

        tree_[val] = root(tree_[val]);
        return tree_[val];
    }

    bool merge(int a, int b)
    {
        int ra = root(a);
        int rb = root(b);

        if (ra == rb)
            return false;

        if (rank_[ra] < rank_[rb]) {
            tree_[ra] = rb;
        }
        else if (rank_[rb] < rank_[ra]) {
            tree_[rb] = ra;
        }
        else {
            tree_[ra] = rb;
            ++rank_[rb];
        }

        return true;
    }

private:
    std::vector<int> tree_;
    std::vector<int> rank_;
};

int main()
{
    int nGuests = 0;
    int nSnacks = 0;
    std::cin >> nSnacks >> nGuests;

    Dsu dsu(nSnacks + 1);
    int count = 0;
    for (int i = 0; i < nGuests; ++i) {
        int a = 0;
        int b = 0;
        std::cin >> a >> b;

        count += static_cast<bool>(!dsu.merge(a, b));
    }

    std::cout << count << std::endl;
}
#endif
