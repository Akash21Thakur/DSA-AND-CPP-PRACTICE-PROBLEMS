#include <iostream>
#include <vector>
using namespace std;

// Time : O(m*n)

vector<int> spirallyTraverse(vector<vector<int>> matrix, int r, int c)
{
    vector<int> ans;
    int left = 0, right = c - 1;
    int up = 0, down = r - 1;

    while (left <= right and up <= down)
    {
        // row-1
        for (int i = left; i <= right; i++)
            ans.push_back(matrix[up][i]);
        up++;

        // column-last
        for (int i = up; i <= down; i++)
            ans.push_back(matrix[i][right]);
        right--;

        // row-last
        if (up <= down)
            for (int i = right; i >= left; i--)
                ans.push_back(matrix[down][i]);
        down--;

        // column-1
        if (left <= right)
            for (int i = down; i >= up; i--)
                ans.push_back(matrix[i][left]);
        left++;
    }

    return ans;
}