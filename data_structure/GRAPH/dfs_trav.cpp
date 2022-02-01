#include <iostream>
#include <list>
#include <map>
using namespace std;

template <typename T>
class Graph
{
    map<T, list<T>> l;

public:
    void addEdge(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void dfs_helper(int src, map<int, bool> &visited)
    {
        cout << src << " ";
        visited[src] = true;

        for (auto nbr : l[src])
        {
            if (!visited[nbr])
                dfs_helper(nbr, visited);
        }
    }

    void dfs(int src)
    {
        map<T, bool> visited;

        for (auto node : l)
        {
            int nbr = node.first;
            visited[nbr] = false;
        }

        dfs_helper(src, visited);
    }

    // check for number of connected graph =>dfs algo
    void countGraph()
    {
        map<int, bool> visited;

        for (auto p : l)
        {
            visited[p.first] = false;
        }
        int count = 1;
        for (auto p : l)
        {
            int node = p.first;

            if (!visited[node])
            {
                cout << count << " ---> ";
                dfs_helper(node, visited);
                count++;
                cout << endl;
            }
        }
    }
};

int main()
{
    Graph<int> g;

    // g.addEdge(0, 1);
    // g.addEdge(0, 3);
    // g.addEdge(1, 2);
    // g.addEdge(2, 3);
    // g.addEdge(3, 4);
    // g.addEdge(4, 5);

    // cout << "DFS : " << endl;
    // g.dfs(0);


//COUNT THE NUMBER OF CONNECTED GRAPHS
//DFS FOREST
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(3, 2);
    g.addEdge(1, 2);

    g.addEdge(4, 5);
    g.addEdge(5, 6);

    g.addEdge(7, 8);

    g.addEdge(9, 9);

    cout << "Graph are : \n";
    g.countGraph();
}

//1
