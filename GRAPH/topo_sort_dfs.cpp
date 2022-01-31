#include <iostream>
#include <map>
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
    }

    void dfs_helper(T src, map<T, bool> &visited, list<T> &ordering)
    {
        visited[src] = true;

        for (auto node : l[src])
        {
            if (!visited[node])
                dfs_helper(node, visited, ordering);
        }

        ordering.push_front(src);
        return;
    }

    void dfs()
    {
        map<T, bool> visited;
        list<T> ordering;

        for (auto p : l)
        {
            T node = p.first;
            visited[node] = false;
        }

        for (auto p : l)
        {
            T node = p.first;
            if (!visited[node])
                dfs_helper(node, visited, ordering);
        }

        for(auto p: ordering)
          cout<<p<<endl;
    }
};

int main()
{
    Graph<string> g;
    
    g.addEdge("Python","Data Processing");
    g.addEdge("Python","Pytorch");
    g.addEdge("Python","ML Basic");
    
    g.addEdge("Data Processing","ML Basic");
    g.addEdge("Pytorch","Deep Learning");
    g.addEdge("ML Basic","Deep Learning");
    g.addEdge("Deep Learning","Face Recog");
    g.addEdge("Dataset","Face Recog");

    g.dfs();

}