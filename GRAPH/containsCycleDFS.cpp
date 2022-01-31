#include <iostream>
#include <map>
#include <list>
using namespace std;

class Graph
{
    int V;
    list<int> *l;

public:
    Graph(int v)
    {
        this->V = v;
        l = new list<int>[V];
    }

    void addEdge(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }

    bool helper(int node, int parent, bool *visited)
    {
        visited[node] = true;

        for (int nbr : l[node])
        {
            if (!visited[nbr])
            {
                bool cycle_mila = helper(nbr, node, visited);
                if (cycle_mila)
                    return true;
            }
            else if (nbr != parent)
                return true;
        }
        return false;
    }

    bool isCyclic()
    {
        bool *visited = new bool[V];
        for (int i = 0; i < V; i++)
            visited[i] = false;

        return helper(0, -1, visited);
    }
};

int main()
{
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    if (g.isCyclic())
        cout << "Contains Cycle" << endl;
    else
        cout << "Does Not Contains Cycle" << endl;
}