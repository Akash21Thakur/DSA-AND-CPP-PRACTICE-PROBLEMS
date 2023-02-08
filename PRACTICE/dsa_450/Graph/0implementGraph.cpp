#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *l;

public:
    Graph(int V)
    {
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void bfs(int src)
    {
        // avoid repition and hence infinite loop...visited :)
        vector<bool> visited(V, false);
        queue<int> q;

        q.push(src);
        visited[src] = true;

        while (!q.empty())
        {
            int curr = q.front();
            cout << curr << " ";
            q.pop();

            for (int nbr : l[curr])
            {
                if (!visited[nbr])
                {
                    q.push(nbr);
                    visited[nbr] = true;
                }
            }
        }
    }

    void dfs_helper(int src, vector<bool> &visited)
    {
        cout << src << " ";
        visited[src] = true;

        for (int nbr : l[src])
        {
            if (!visited[nbr])
                dfs_helper(nbr, visited);
        }
    }

    void dfs()
    {
        vector<bool> visited(V, false);

        dfs_helper(0, visited);
    }
};

int main()
{
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    // g.bfs(0);

    g.dfs();
}