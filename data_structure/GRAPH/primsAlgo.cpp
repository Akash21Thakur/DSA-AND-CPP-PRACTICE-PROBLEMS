#include <iostream>
#include <list>
#include <queue>
#include <vector>
using namespace std;

class Graph
{
    int V;
    list<pair<int, int>> *l;

public:
    Graph(int v)
    {
        this->V = v;
        l = new list<pair<int, int>>[v + 1];
    }

    void addEdge(int x, int y, int w)
    {
        l[x].push_back({y, w});
        l[y].push_back({x, w});
    }

    int prim_mst()
    {
        // min heap
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;

        bool *visited = new bool[V + 1]{0};

        Q.push({0, 1});
        int ans = 0;

        while (!Q.empty())
        {
            auto best = Q.top();
            Q.pop();

            int y = best.second;
            int weight = best.first;

            if (visited[y] == 1)
                continue;

            ans += weight;
            visited[y] = 1;

            for (auto temp : l[y])
            {
                if (visited[temp.first] != 1)
                {
                    Q.push({temp.second, temp.first});
                }
            }
        }

        return ans;
    }
};

int main()
{
    Graph g(9);

    // g.addEdge(0,1,1);
    // g.addEdge(0,2,2);
    // g.addEdge(0,3,2);
    // g.addEdge(1,2,2);
    // g.addEdge(1,3,4);
    // g.addEdge(2,3,3);

    g.addEdge(1, 2, 10);
    g.addEdge(1, 3, 12);
    g.addEdge(2, 3, 9);
    g.addEdge(2, 4, 8);
    g.addEdge(3, 5, 3);
    g.addEdge(3, 6, 1);
    g.addEdge(5, 4, 7);
    g.addEdge(5, 6, 3);
    g.addEdge(4, 6, 10);
    g.addEdge(6, 8, 6);
    g.addEdge(4, 7, 8);
    g.addEdge(4, 8, 5);
    g.addEdge(7, 8, 9);
    g.addEdge(7, 9, 2);
    g.addEdge(8, 9, 11);

    cout << g.prim_mst() << endl;
}