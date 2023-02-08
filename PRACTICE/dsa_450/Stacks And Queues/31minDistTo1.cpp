//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
	int n, m;
	int X[4] = {-1, 0, 1, 0};
	int Y[4] = {0, 1, 0, -1};

	bool isValid(int x, int y)
	{
		if (x < 0 or x >= n or y < 0 or y >= m)
			return false;
		return true;
	}

	// Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>> nearest(vector<vector<int>> grid)
	{
		n = grid.size(), m = grid[0].size();
		vector<vector<int>> ans(n, vector<int>(m, -1));

		// insert in q idx. containing 1
		queue<pair<int, int>> q;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (grid[i][j] == 1)
				{
					q.push({i, j});
					ans[i][j] = 0; // distance is 0
				}
			}
		}

		// simple bfs...curr's neighbour has +1 distance
		while (!q.empty())
		{
			pair<int, int> curr = q.front();
			q.pop();
			for (int i = 0; i < 4; i++)
			{
				int x = curr.first + X[i];
				int y = curr.second + Y[i];

				if (isValid(x, y) and ans[x][y] == -1)
				{
					q.push({x, y});
					ans[x][y] = ans[curr.first][curr.second] + 1;
				}
			}
		}
		return ans;
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
		vector<vector<int>> ans = obj.nearest(grid);
		for (auto i : ans)
		{
			for (auto j : i)
			{
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends