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

    bool isGraphTree()
    {
        bool *visited = new bool[V];
        for (int i = 0; i < V; i++)
            visited[i] = false;

        if (helper(0, -1, visited))
            return false;

        // if not cyclic...
        // we need to check if all vertices are connected
        // check if all vertex have atlest one entry in resp. idx of adjacency list
        for (int v = 0; v < V; v++)
        {
            if (visited[v] == false)
                return false;
        }

        // hence the graph is neither cyclic nor disconnected
        // means is TREE
        return true;
    }
};

int main()
{
    // Graph g1(5);
    // g1.addEdge(1, 0);
    // g1.addEdge(0, 2);
    // g1.addEdge(0, 3);
    // g1.addEdge(3, 4);

    Graph g2(5);
    g2.addEdge(1, 0);
    g2.addEdge(0, 2);
    g2.addEdge(2, 1);
    g2.addEdge(0, 3);
    g2.addEdge(3, 4);

    if (g2.isGraphTree())
        cout << "GRAPH IS TREE" << endl;
    else
        cout << "GRPH IS NOT TREE" << endl;
}