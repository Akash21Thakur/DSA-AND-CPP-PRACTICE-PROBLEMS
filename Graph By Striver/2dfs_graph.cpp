#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<int> &visited, int node, vector<int> graph[])
{
    cout << node << " ";
    visited[node] = 1;

    for (auto it : graph[node])
    {
        if (!visited[it])
            dfs(visited, it, graph);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> graph[n + 1];
    vector<int> visited(n + 1, 0);
    // vector<int> ans;
    int u, v;

    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(visited, 1, graph);
}