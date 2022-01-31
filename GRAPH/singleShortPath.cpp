#include <iostream>
#include <map>
#include <list>
#include <queue>
#include <climits>

using namespace std;

class Graph
{
    map<int, list<int>> mp;

public:
    void addEdge(int x, int y)
    {
        mp[x].push_back(y);
        mp[y].push_back(x);
    }

    void singleSrcShrtPath(int src)
    {
        map<int, int> dist;
        queue<int> q;

        for (auto node_pair : mp)
        {
            int node = node_pair.first;
            dist[node] = INT_MAX;
        }

        dist[src] = 0;
        q.push(src);

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (int nbr : mp[node])
            {
                if (dist[nbr] == INT_MAX)
                {
                    q.push(nbr);
                    dist[nbr] = dist[node] + 1;
                }
            }
        }

        for (auto node_pair : mp)
        {
            int temp = node_pair.first;
            int d = dist[temp];
            cout << "Dist of " << temp
                 << " from " << src << " : " << d << endl;
        }
    }
};

int main()
{
    Graph g;
    g.addEdge(0,1);
    g.addEdge(0,3);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
   
    g.singleSrcShrtPath(0);
}