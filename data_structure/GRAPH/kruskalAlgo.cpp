#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class DSU
{
    int V;
    int *parent;
    int *rank;

public:
    DSU(int v)
    {
        this->V = v;
        parent = new int[v];
        rank = new int[v];

        for (int i = 0; i < V; i++)
        {
            parent[i] = -1;
            rank[i] = 1;
        }
    }

    // find by path compression
    int find(int x)
    {
        if (parent[x] == -1)
            return x;

        return parent[x] = find(parent[x]);
    }

    // unite by path compression
    void unite(int x, int y)
    {
        int s1 = find(x);
        int s2 = find(y);

        if (s1 != s2)
        {
            if (rank[s1] < rank[s2])
            {
                parent[s1] = s2;
                rank[s2] += rank[s1];
            }
            else
            {
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
        }
    }
};

class Graph
{
    vector<vector<int>> edgeList; // contains three value => weight,x,y
    int V;

public:
    Graph(int v)
    {
        this->V = v;
    }

    void addEdge(int x, int y, int w)
    {
        edgeList.push_back({w, x, y});
    }

    int kruskal_mst()
    {
        sort(edgeList.begin(), edgeList.end());
        int ans=0;
        DSU d(V);

        for (auto edge : edgeList)
        {
            int w = edge[0];
            int x = edge[1];
            int y = edge[2];

            if(d.find(x)!=d.find(y))
            {
                d.unite(x,y);
                cout<<w<<" ";
                ans+=w;
            }
        }
        cout<<endl;
        return ans;
    }
};

int main()
{
    Graph g(9);

    // g.addEdge(1,2,1);
    // g.addEdge(1,3,2);
    // g.addEdge(1,4,2);
    // g.addEdge(2,3,2);
    // g.addEdge(2,4,4);
    // g.addEdge(3,4,3);

    g.addEdge(1,2,10);
    g.addEdge(1,3,12);
    g.addEdge(2,3,9);
    g.addEdge(2,4,8);
    g.addEdge(3,5,3);
    g.addEdge(3,6,1);
    g.addEdge(5,4,7);
    g.addEdge(5,6,3);
    g.addEdge(4,6,10);
    g.addEdge(6,8,6);
    g.addEdge(4,7,8);
    g.addEdge(4,8,5);
    g.addEdge(7,8,9);
    g.addEdge(7,9,2);
    g.addEdge(8,9,11);

    cout<<g.kruskal_mst()<<endl;
}