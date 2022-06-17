// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
    // Striver
public:
    int x[4] = {1, 0, 0, -1};
    int y[4] = {0, -1, 1, 0};

    string s = "DLRU"; // lexo_order

    void solve(int i, int j, vector<vector<int>> &m, int n, vector<string> &ans, vector<vector<int>> &visited, string path)
    {
        /*
        // if(i==n-1 and j==n-1){
        //     ans.push_back(path);
        //     return;
        // }

        // // lexo_order= DLRU
        // //downward
        // if(i+1<n and !visited[i+1][j] and m[i+1][j]==1)
        // {
        //     visited[i][j]=1;
        //     solve(m,n,ans,visited,path+'D',i+1,j);
        //     visited[i][j]=0;
        // }
        // //left
        // if(j-1>=0 and !visited[i][j-1] and m[i][j-1]==1)
        // {
        //     visited[i][j]==1;
        //     solve(m,n,ans,visited,path+'L',i,j-1);
        //     visited[i][j]==0;
        // }

        // //right
        // if(j+1<n and !visited[i][j+1] and m[i][j+1]==1)
        // {
        //     visited[i][j]==1;
        //     solve(m,n,ans,visited,path+'R',i,j+1);
        //     visited[i][j]==0;
        // }
        // //up
        // if(i-1>=0 and !visited[i-1][j] and m[i-1][j]==1)
        // {
        //     visited[i][j]==1;
        //     solve(m,n,ans,visited,path+'U',i-1,j);
        //     visited[i][j]==0;
        // }
        */
        // reached the destination
        if (i == n - 1 and j == n - 1)
        {
            ans.push_back(path);
            return;
        }

        // down_left_right_up
        for (int k = 0; k < 4; k++)
        {
            int new_x = i + x[k];
            int new_y = j + y[k];
            // check the boundary and necessary condition for path to exist
            if (new_x >= 0 and new_x < n and new_y >= 0 and new_y < n and visited[new_x][new_y] == 0 and m[new_x][new_y] == 1)
            {
                visited[i][j] = 1; // mark the current cell visited
                solve(new_x, new_y, m, n, ans, visited, path + s[k]);
                visited[i][j] = 0; // while backtracking mark not visited
            }
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        vector<string> ans;
        vector<vector<int>> visited(n, vector<int>(n, 0)); // keeps track of single path at any moment
        if (m[0][0] == 1)                                  // if first cell is 1 than only any path exist
            solve(0, 0, m, n, ans, visited, "");
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
} // } Driver Code Ends