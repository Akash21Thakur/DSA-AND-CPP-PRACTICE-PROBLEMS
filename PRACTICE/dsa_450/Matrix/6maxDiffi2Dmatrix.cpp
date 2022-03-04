#include <iostream>
#include <vector>
#include<climits>
using namespace std;

//NOT_COMPLETED_UNDERSTOOD

// ref link : https://www.geeksforgeeks.org/find-a-specific-pair-in-matrix/


// method-1 (brute-force)
//  uses 4-loops

// optimal-Time: O(n*n) Space : O(n*n)
int findMaxDiff(vector<vector<int>> &v)
{
    int n = v.size();
    vector<vector<int>> maxMatrix(n, vector<int>(n));

    maxMatrix[n-1][n-1]=v[n-1][n-1];
    int maxi=maxMatrix[n-1][n-1];

    //last row
    for(int j=n-2;j>=0;j--)
    {
        maxi=max(maxi,v[n-1][j]);
        maxMatrix[n-1][j]=maxi;

    }

    //last column
    maxi=maxMatrix[n-1][n-1];
    for(int j=n-2;j>=0;j--)
    {
        maxi=max(maxi,v[j][n-1]);
        maxMatrix[j][n-1]=maxi;
    }

    //for the rest matrix
    int maxVal=INT_MIN;
    for(int i=n-2;i>=0;i--)
    {
        for(int j=n-2;j>=0;j--)
        {
            maxVal=max(maxMatrix[i+1][j+1]-v[i][j],maxVal);
            maxMatrix[i][j]=maxVal;
        }
    }
    return maxi;
}
int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> v(n, vector<int>(m));
    cout << "Enter the elements : " << endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> v[i][j];

    cout << findMaxDiff(v) << endl;
}