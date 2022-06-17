// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    // we can also check the isSafe by maintaining a hashmap as below:
    // 1.Cur_row= size:n...mark visited once passed for all the columns in that row
    // 2.Lower Left Diagonal=size(2n-1)...mark row+col visited
    // 3. Upper Left Diagonal=size(2n-1)...(n-1)+(col-row) mark visited
    void solve2(vector<int> &leftRow, vector<int> &upperDia, vector<int> &lowerDia, vector<vector<int>> &ans, vector<vector<int>> &board, int n, int col, vector<int> &v)
    {
        if (col == n)
        {
            ans.push_back(v);
            return;
        }

        for (int row = 0; row < n; row++)
        {
            // isSafe func. alternative
            if (leftRow[row] == 0 and upperDia[(n - 1) + (col - row)] == 0 and lowerDia[row + col] == 0)
            {
                // mark all visited
                board[row][col] = 1;
                leftRow[row] = 1;
                upperDia[(n - 1) + (col - row)] = 1;
                lowerDia[row + col] = 1;
                v.push_back(row + 1);

                solve2(leftRow, upperDia, lowerDia, ans, board, n, col + 1, v);

                // unmark while backtracking
                board[row][col] = 0;
                leftRow[row] = 0;
                upperDia[(n - 1) + (col - row)] = 0;
                lowerDia[row + col] = 0;
                v.pop_back();
            }
        }
    }
    bool isSafe(int row, int col, vector<vector<int>> &board, int n)
    {
        // Queen can move in 8 direction...but we need only to check only 3
        //  as rest are not visited for sure

        // check in the upper left diagonal
        int temp_row = row;
        int temp_col = col;

        while (temp_row >= 0 and temp_col >= 0)
        {
            if (board[temp_row][temp_col] == 1)
                return false;
            temp_row--;
            temp_col--;
        }

        // check in the current row prev. columns
        temp_col = col;
        while (temp_col >= 0)
        {
            if (board[row][temp_col] == 1)
                return false;
            temp_col--;
        }

        // check for below left diagonal
        temp_row = row;
        temp_col = col;
        while (temp_row < n and temp_col >= 0)
        {
            if (board[temp_row][temp_col] == 1)
                return false;
            temp_row++;
            temp_col--;
        }

        return true;
    }
    void solve(int col, vector<vector<int>> &board, vector<vector<int>> &ans, int n, vector<int> &cur_row)
    {
        // base case...when we reach nth col. means we have successfully placed n-Queens
        if (col == n)
        {
            ans.push_back(cur_row);
            return;
        }

        // check for each row in that column
        for (int row = 0; row < n; row++)
        {
            if (isSafe(row, col, board, n))
            {
                cur_row.push_back(row + 1);
                board[row][col] = 1;

                // check for next column
                solve(col + 1, board, ans, n, cur_row);

                // revert while backtracking
                board[row][col] = 0;
                cur_row.pop_back();
            }
        }
    }
    vector<vector<int>> nQueen(int n)
    {
        vector<vector<int>> ans;
        vector<int> cur_row;
        vector<vector<int>> board(n, vector<int>(n, 0));

        // solve(0,board,ans,n,cur_row);

        // isSSafe alternative
        vector<int> leftRow(n, 0);
        vector<int> upperDia(2 * n, 0);
        vector<int> lowerDia(2 * n, 0);
        solve2(leftRow, upperDia, lowerDia, ans, board, n, 0, cur_row);
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

        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if (ans.size() == 0)
            cout << -1 << "\n";
        else
        {
            for (int i = 0; i < ans.size(); i++)
            {
                cout << "[";
                for (int u : ans[i])
                    cout << u << " ";
                cout << "] ";
            }
            cout << endl;
        }
    }
    return 0;
} // } Driver Code Ends