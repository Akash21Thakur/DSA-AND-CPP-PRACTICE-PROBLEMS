#include <iostream>
#include <list>
using namespace std;

class Graph
{
    list<int> *l;
    int V;

public:
    Graph(int v)
    {
        this->V = v;
        l = new list<int>[V];
    }

    void addEdge(int x, int y)
    {
        l[x].push_back(y);
    }

    bool cycleHepler(int node, bool *visited, bool *stack)
    {
        visited[node] = true;
        stack[node] = true;

        for (int nbr : l[node])
        {
            if (stack[nbr] == true)
                return true;
            else if (visited[nbr] == false)
            {
                bool temp = cycleHepler(nbr, visited, stack);
                if (temp)
                    return true;
            }
        }

        stack[node] = false;
        return false;
    }

    bool containsCycle()
    {
        bool *visited = new bool[V];
        bool *stack = new bool[V];

        for (int i = 0; i < V; i++)
        {
            visited[i] = stack[i] = false;
        }

        return cycleHepler(0, visited, stack);
    }
};

int main()
{
    Graph g(7);

    g.addEdge(0,1);
    g.addEdge(1,5);
    g.addEdge(5,6);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(4,2);
    // g.addEdge(,);

    if(g.containsCycle())
    cout<<"CONTAINS CYCLE"<<endl;
    else cout<<"NOT CONTAINS CYCLE"<<endl;
}