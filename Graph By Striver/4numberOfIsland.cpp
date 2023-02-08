#include <bits/stdc++.h>
using namespace std;

// A simple dfs solution where if 1 found ...searches in all its 4 neighbour...and moves to that,
// making own value 0...so that its not again visited avoiding infinite loop

class Solution
{
    int x[4] = {-1, 0, 1, 0};
    int y[4] = {0, 1, 0, -1};
    int n, m;

    void visitAndChange(vector<vector<char>> &grid, int i, int j)
    {
        if (i < 0 or i >= n or j < 0 or j >= m or grid[i][j] == '0')
            return;

        // so that is does not visit the grid again
        grid[i][j] = '0';

        for (int k = 0; k < 4; k++)
            visitAndChange(grid, i + x[k], j + y[k]);
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        int count = 0;
        n = grid.size();
        m = grid[0].size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                // ..means island found ...not need to look its neighbors
                if (grid[i][j] == '1')
                {
                    count++;
                    visitAndChange(grid, i, j);
                }
            }
        }
        return count;
    }
};