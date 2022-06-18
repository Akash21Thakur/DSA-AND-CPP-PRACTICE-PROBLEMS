// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid
#define UNASSIGNED 0

// N is used for the size of Sudoku grid.
// Size will be NxN
#define N 9

// } Driver Code Ends
class Solution
{
public:
    // check for cur_row,cur_col,cur_3X3_grid if we can place the num

    bool canPlace(int grid[N][N], int i, int j, int num)
    {
        // row and col
        for (int k = 0; k < 9; k++)
        {
            if (grid[i][k] == num or grid[k][j] == num)
                return false;
        }

        // sx and sy gives the start of curr pos. 3x3 grid
        int sx = (i / 3) * 3, sy = (j / 3) * 3;
        for (int m = sx; m < sx + 3; m++)
        {
            for (int n = sy; n < sy + 3; n++)
            {
                if (grid[m][n] == num)
                    return false;
            }
        }
        return true;
    }

    bool helper(int grid[N][N], int i, int j)
    {
        // base case
        if (i == N)
        {
            // printGrid(grid);
            return true;
        }

        // all col. in a row done
        if (j == N)
        {
            return helper(grid, i + 1, 0);
        }

        // if cell is filled
        if (grid[i][j] != 0)
            return helper(grid, i, j + 1);

        // check for all the numbers
        for (int k = 1; k <= 9; k++)
        {
            if (canPlace(grid, i, j, k))
            {
                grid[i][j] = k;

                bool temp = helper(grid, i, j + 1);
                // if found the answer for nexx subarray...just return true from here
                if (temp)
                    return true;
                // revert while backtracking
                grid[i][j] = 0;
            }
        }

        return false;
    }

    // Function to find a solved Sudoku.
    bool SolveSudoku(int grid[N][N])
    {
        return helper(grid, 0, 0);
    }

    // Function to print grids of the Sudoku.
    void printGrid(int grid[N][N])
    {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                cout << grid[i][j] << " ";
        // cout<<endl; }
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int grid[N][N];

        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                cin >> grid[i][j];

        Solution ob;

        if (ob.SolveSudoku(grid) == true)
            ob.printGrid(grid);
        else
            cout << "No solution exists";

        cout << endl;
    }

    return 0;
} // } Driver Code Ends