// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Function to determine if graph can be coloured with at most M colours such
// that no two adjacent vertices of graph are coloured with same colour.

// Striver's Soln.   similar to sudoko solver

// checks if we can place color(val) in the current node
bool canPlace(int node, int n, bool graph[101][101], int *color, int val)
{
    for (int k = 0; k < n; k++)
    {
        // if nodes are neighbour and color is same return false
        if (node != k and graph[k][node] == 1 and color[k] == val)
            return false;
    }
    return true;
}

bool helper(int node, int m, int n, bool graph[101][101], int *color)
{
    // base case...means we were able to color nodes with <=m color
    if (node == n)
        return true;

    for (int i = 1; i <= m; i++)
    {
        if (canPlace(node, n, graph, color, i))
        {
            color[node] = i;

            // is the subproblem can be solved return true
            if (helper(node + 1, m, n, graph, color))
                return true;

            // backtracking
            color[node] = 0;
        }
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int n)
{
    int color[n + 1] = {0};
    return helper(0, m, n, graph, color);
}

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++)
        {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++)
        {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
// } Driver Code Ends