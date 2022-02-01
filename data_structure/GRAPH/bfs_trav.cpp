#include <iostream>
#include <map>
#include <queue>
#include <list>

using namespace std;

template <typename T>
class Graph
{
    map<T, list<T>> l;

public:
    void addEdge(T x, T y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void bfs(T src)
    {
        map<T, bool> visited;
        queue<T> q;

        q.push(src);
        visited[src] = true;

        while (!q.empty())
        {
            T temp = q.front();
            q.pop();

            cout << temp << " ";

            for (string nbr : l[temp])//traverse for all the neighbour of temp
            {
                if (!visited[nbr])//new new node
                {
                    q.push(nbr);
                    visited[nbr] = true;//mark the visited node as visited
                }
            }
        }
    }
};

/*

C-----B
|     |
|     |
D-----A
|
|
E-----F

*/

int main()
{
    Graph<string> g;
    g.addEdge("A", "B");
    g.addEdge("A", "D");
    g.addEdge("B", "C");
    g.addEdge("C", "D");
    g.addEdge("D", "E");
    g.addEdge("E", "F");
   
    g.bfs("F");
}