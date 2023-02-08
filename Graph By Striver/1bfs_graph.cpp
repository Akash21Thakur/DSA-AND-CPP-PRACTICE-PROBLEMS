#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector<int> &visited, int start, vector<int> graph[])
{
    queue<int> q;
    q.push(start);

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        cout << curr << " ";
        visited[curr] = 1;

        for (int i = 0; i < graph[curr].size(); i++)
        {
            if (!visited[graph[curr][i]])
            {
                visited[graph[curr][i]] = 1;
                q.push(graph[curr][i]);
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> visited(n + 1, 0);
    vector<int> graph[n + 1];
    int u, v;

    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
            bfs(visited, i, graph);
    }
}