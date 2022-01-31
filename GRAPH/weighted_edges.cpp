#include <iostream>
#include <map>
#include <list>
using namespace std;

class Graph
{
    map<string, list<pair<string, int>>> l;

public:
    void addEdges(string x, string y, bool bidir, int wt)
    {
        l[x].push_back(make_pair(y, wt));
        if (bidir)
        {
            l[y].push_back(make_pair(x, wt));
        }
    }

    void printAll()
    {
        for (auto p : l)
        {
            list<pair<string, int>> temp = p.second;
            cout << p.first << " -> ";
            for (auto t : temp)
            {
                string s = t.first;
                int weight = t.second;

                cout << "(" << s << "," << weight << ") , ";
            }
            cout << endl;
        }
    }
};

int main()
{
    // cout<<"Akash Thakur"<<endl;
    Graph g;
    g.addEdges("A", "B", true, 20);
    g.addEdges("A", "C", true, 10);
    g.addEdges("A", "D", false, 50);
    g.addEdges("B", "D", true, 30);
    g.addEdges("C", "D", true, 40);

    g.printAll();
}