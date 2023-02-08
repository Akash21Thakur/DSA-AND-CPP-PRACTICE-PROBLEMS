#include <bits/stdc++.h>
using namespace std;

// simple dfs or bfs to count number of connected component in the graph
class Solution
{

    void dfs(vector<int> &vis, int curr, vector<int> adj[])
    {
        vis[curr] = 1;

        for (auto node : adj[curr])
        {
            if (vis[node] != 1)
                dfs(vis, node, adj);
        }
    }

    void bfs(vector<int> &vis, int cur, vector<int> adj[])
    {
        queue<int> q;
        q.push(cur);

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            vis[node] = 1;

            for (auto it : adj[node])
            {
                if (vis[it] != 1)
                    q.push(it);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int v = isConnected.size();

        // convert into adj_list
        vector<int> adj[v];
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                if (isConnected[i][j] == 1)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        // visited array
        vector<int> vis(v, 0);

        int count = 0;
        for (int i = 0; i < v; i++)
        {
            if (vis[i] != 1)
            {
                count++;
                bfs(vis, i, adj);
            }
        }
        return count;
    }
};