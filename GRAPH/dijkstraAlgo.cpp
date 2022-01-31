#include <bits/stdc++.h>
using namespace std;

class Graph
{
    map<int, list<pair<int, int>>> mp;
    int V;

public:
    Graph(int v)
    {
        this->V = v;
    }

    void addEdge(int x, int y, int wt)
    {
        mp[x].push_back(make_pair(y, wt));
        mp[y].push_back(make_pair(x, wt));
    }

    void dijkstraAlgo(int src)
    {
        vector<int> distAr(V + 1, INT_MAX);
        priority_queue<pair<int, int>> pq;

        distAr[src] = 0;
        pq.push(make_pair(0, src));

        while (!pq.empty())
        {
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto it : mp[node])
            {
                int nextNode = it.first;
                int nextDist = it.second;

                if (distAr[nextNode] > dist + nextDist)
                {
                    distAr[nextNode] = dist + nextDist;
                    pq.push(make_pair(distAr[nextNode], nextNode));
                }
            }
        }

        // printing the shortest distance
        for (int i = 0; i <= V; i++)
            cout << "Dist of " << i << " from " << src << " is: " << distAr[i] << endl;
    }
};

int main()
{
    Graph g(4);
    g.addEdge(0, 1, 3);
    g.addEdge(0, 4, 8);
    g.addEdge(0, 3, 7);
    g.addEdge(1, 3, 4);
    g.addEdge(1, 2, 1);
    g.addEdge(2, 3, 2);
    g.addEdge(3, 4, 3);

    g.dijkstraAlgo(0);
}
