#include<bits/stdc++.h>
using namespace std;

int minPathSum(vector<vector<int>>& a) {
        int n=a.size();
        int m=a[0].size();
        int dp[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 and j == 0)
                dp[i][j] = a[i][j];
            else if (i == 0)
                dp[i][j] = dp[i][j - 1] + a[i][j];
            else if (j == 0)
                dp[i][j] = dp[i - 1][j] + a[i][j];
            else
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + a[i][j];
        }
    }
    return dp[n - 1][m - 1];
    }

 int main()
 {
     vector<vector<int>> v;
     int n,m;
     cin>>n>>m;
     int temp;
     for(int i=0;i<n;i++)
     {
         vector<int> t;
         for(int j=0;j<m;j++)
         {
             cin>>temp;
            //  cout<<"akash ";
             t.push_back(temp);
         }
         v.push_back(t);
     }
    //  for(int i=0;i<n;i++)
    //  {
    //      for(int j=0;j<m;j++)
    //      cout<<v[i][j]<<" ";
    //      cout<<endl;
    //  }
     cout<<"Minimum cost path : "<<minPathSum(v)<<endl;
 }   