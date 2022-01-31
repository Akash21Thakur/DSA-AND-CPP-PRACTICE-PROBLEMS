#include <iostream>
#include <list>
using namespace std;

class Graph
{
    int V;
    list<pair<int, int>> l;

public:
    Graph(int v)
    {
        this->V = v;
    }

    void addEdge(int x, int y)
    {
        l.push_back(make_pair(x, y));
    }

    // FIND
    int findHead(int i, int *parent)
    {
        if (parent[i] == -1)
            return i;

        findHead(parent[i], parent);
    }

    // UNION
    void unionSet(int x, int y, int *parent)
    {
        int s1 = findHead(x, parent);
        int s2 = findHead(y, parent);

        if (s1 != s2)
            parent[s2] = s1;
    }

    // check function
    bool isCycle()
    {
        int *parent = new int[V];

        for (int i = 1; i <= V; i++)
            parent[i] = -1;

        for (auto edge : l)
        {
            int i = edge.first;
            int j = edge.second;

            int s1 = findHead(i, parent);
            int s2 = findHead(j, parent);

            if (s1 != s2)
                unionSet(i, j, parent);
            else
                return true;
        }
        delete[] parent;
        return false;
    }
};

int main()
{
    Graph g(4);

    g.addEdge(1, 2);
    g.addEdge(3, 4);
    g.addEdge(2, 3);
    // g.addEdge(1, 4);

    if (g.isCycle())
        cout << "CYCLE IS FOUND" << endl;
    else
        cout << "CYCLE NOT FOUND" << endl;
}