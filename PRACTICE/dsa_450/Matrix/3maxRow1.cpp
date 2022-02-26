#include <iostream>
#include <vector>
using namespace std;
// method-1  O(n*m)
//  linear search in each row of the matrix

// method-2  O(nlogm)
//  search in each row can be optimized applying the binary searchenv

// method-3 optimal O(m+n)
//  search from row-1 from back and continue the search in next row from the next-row-prev-column number
int rowWithMax1s(vector<vector<int>> arr, int n, int m)
{
    int count = 0, row = 0;
    // int n=arr.size();
    // int m=arr[0].size();
    int j = m - 1; // column
    for (int i = 0; i < n; i++)
    {
        int temp = count;
        for (; j >= 0; j--)
        {
            if (arr[i][j] == 1)
                temp++;
            else
                break;
        }
        if (temp > count)
        {
            cout << temp << " ";
            row = i;
            count = temp;
        }
    }
    cout << endl;
    return row;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> arr(n, vector<int>(m));
    int temp;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    cout << rowWithMax1s(arr, n, m) << endl;
}