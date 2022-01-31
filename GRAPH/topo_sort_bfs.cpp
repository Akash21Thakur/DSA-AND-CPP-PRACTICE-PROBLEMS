#include <iostream>
#include <list>
#include <queue>
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
        // directed graph
        l[x].push_back(y);
    }

    void topo_sort_bfs()
    {
        // indegree of all nodes
        int *indegree = new int[V];

        // intially intialize all the nodes with 0
        for (int i = 0; i < V; i++)
            indegree[i] = 0;

        // update the indegree as per the graph
        for (int i = 0; i < V; i++)
        {
            for (auto p : l[i])
                indegree[p]++;
        }

        // BFS
        // add into queue the node with 0 indegree i.e. starting node
        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }

        while (!q.empty())
        {
            int temp = q.front();
            cout << temp << " ";
            q.pop();

            // iterate over the nbr of temp_node, decreasing the indegree by 1
            // and adding to the queue if it bbecomes "0"
            for (auto nbr : l[temp])
            {
                indegree[nbr]--;
                if (indegree[nbr] == 0)
                    q.push(nbr);
            }
        }
    }
};

int main()
{
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(2, 5);
    g.addEdge(4, 5);
    g.addEdge(3, 5);

    g.topo_sort_bfs();
}