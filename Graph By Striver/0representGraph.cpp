#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m; // nodes and edges

    cin >> n >> m;

    // method-1   Adjacency Matrix
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, 0));

    int u, v;
    // for (int i = 0; i < m; i++)
    // {
    //     cin >> u >> v;
    //     graph[u][v] = 1; // for weighted graph store weights instead of 1
    //     graph[v][u] = 1;
    // }

    // method-1 output
    // cout << "Adjacency Matrix : " << endl;
    // for (int i = 0; i <= n; i++)
    // {
    //     for (int j = 0; j <= n; j++)
    //         cout << graph[i][j] << " ";

    //     cout << endl;
    // }

    // method-2 adjacency list

    vector<int> adj_list[n + 1]; // vector of pair instead of int when weighted graph
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
    {
        cout << i << " ---> ";
        for (int j = 0; j < adj_list[i].size(); j++)
            cout << adj_list[i][j] << " ";

        cout << endl;
    }
}