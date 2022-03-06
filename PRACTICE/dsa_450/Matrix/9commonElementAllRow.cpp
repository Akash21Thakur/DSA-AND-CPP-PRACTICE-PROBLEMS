#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

void findCommon(vector<vector<int>> &v)
{
    int n=v.size();

    unordered_map<int,int> mp;

    //insert 1st row
    for(int i=0;i<n;i++)
      mp[v[0][i]]=1;

    for(int i=1;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(mp[v[i][j]]==i)
              mp[v[i][j]]++;

            if(i==n-1 and mp[v[i][j]]==n)
               cout<<v[i][j]<<" ";  
        }
    }  

}

int main()
{
    int n;
    cin>>n;
    vector<vector<int>> v {
        {1, 2, 1, 4, 8},
        {3, 7, 8, 5, 1},
        {8, 7, 7, 3, 1},
        {8, 1, 2, 7, 9},
        {8, 1, 2, 7, 9},
    };

    // for(int i=0;i<n;i++)
    //   for(int j=0;j<n;j++)
    //     cin>>v[i][j];

    findCommon(v);    
}
