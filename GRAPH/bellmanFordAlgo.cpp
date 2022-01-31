#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<int> bellmanFord(int n, int src, vector<vector<int>> &edges)
{
    vector<int> dist(n + 1, INT_MAX);
    dist[src] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (auto edge : edges)
        {
            int x = edge[0];
            int y = edge[1];
            int wt = edge[2];

            if (dist[x] != INT_MAX and dist[x] + wt < dist[y])
                dist[y] = dist[x] + wt;
        }
    }

    for (auto edge : edges)
    {
        int x = edge[0];
        int y = edge[1];
        int wt = edge[2];

        if (dist[x] != INT_MAX and dist[x] + wt < dist[y])
        {
            cout << "NEGATIVE WEIGTH GRAPH" << endl;
            exit(0);
        }
    }

    return dist;
}

int main()
{
    int n = 3;

    // vector<vector<int>> edges{{1, 2, 2},
    //                           {1, 3, 3},
    //                           {2, 3, 2},
    //                           {3, 4, 5},
    //                           {4, 5, 6},
    //                           {4, 6, 10},
    //                           {5, 6, 7}};

    vector<vector<int>> edges{{1, 2, 2},
                              {2, 3, -4},
                              {3, 1, 1}};

    vector<int> ans = bellmanFord(n, 1, edges);

    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
}