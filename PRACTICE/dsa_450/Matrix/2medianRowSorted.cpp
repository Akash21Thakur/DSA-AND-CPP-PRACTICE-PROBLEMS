#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int median(vector<vector<int>> &matrix, int r, int c)
{
    int mini = INT_MAX, maxi = INT_MIN;

    //find the minimum and maximum in the matrix
    for (int i = 0; i < r; i++)
    {
        mini = min(mini, matrix[i][0]);
        maxi = max(maxi, matrix[i][c - 1]);
    }

    // number of element required to be in the first half of the final array
    // elements before median
    int first_half = (r * c + 1) / 2;

    while (mini < maxi)
    {
        int mid = mini + (maxi - mini) / 2;
        
        //counts the  number of element less than the current mid in the matrix
        int count = 0;
        for (int i = 0; i < r; i++)
            count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
        
        //if count is less than required ... means median is in the current 2nd half
        if (count < first_half)
            mini = mid + 1;
        else  // else minimize the search space to first half
            maxi = mid;
    }

    return mini;  // required median
}

int main()
{
    int r, c;
    cin >> r >> c;

    vector<vector<int>> v(r, vector<int>(c));

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> v[i][j];

    cout << median(v, r, c) << endl;
}
