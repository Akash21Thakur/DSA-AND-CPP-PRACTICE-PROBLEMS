//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    bool isValid(int x, int y, int n, int m)
    {
        if (x < 0 or x >= n or y < 0 or y >= m)
            return false;
        return true;
    }

    // Function to find minimum time required to rot all oranges.
    int orangesRotting(vector<vector<int>> &grid)
    {

        int X[4] = {-1, 0, 1, 0};
        int Y[4] = {0, 1, 0, -1};

        queue<pair<int, int>> q;
        int n = grid.size();
        int m = grid[0].size();
        // first put the rotten ones
        int one = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                    q.push({i, j});
                else if (grid[i][j] == 1)
                    one++;
            }
        }
        int count = 0, marked = 0;
        // check for each inserted element's neighbour...
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                auto curr = q.front();
                q.pop();
                for (int k = 0; k < 4; k++)
                {
                    int x = curr.first + X[k];
                    int y = curr.second + Y[k];

                    if (isValid(x, y, n, m) and grid[x][y] == 1)
                    {
                        grid[x][y] = 2;
                        q.push({x, y});
                        marked++;
                    }
                }
            }
            if (!q.empty())
                count++;
        }

        if (marked == one)
            return count;
        return -1;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.orangesRotting(grid);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends