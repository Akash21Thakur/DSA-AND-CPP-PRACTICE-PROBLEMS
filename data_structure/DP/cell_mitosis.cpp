#include<iostream>
using namespace std;

int cellMito(int n,int x,int y,int z)
{
    int dp[n+1]={0};
    dp[0]=0;
    dp[1]=0; //=>base case

    for(int i=2;i<=n;i++)
    {
        if(i&1)
        {
            dp[i]=min(dp[i-1]+y,dp[(i+1)/2]+x+z);
        }
        else
        {
            dp[i]=min(dp[i-1]+y,dp[i/2]+x);
        }
    }

    return dp[n];

}

int main()
{
    int n,x,y,z;
    cin>>n>>x>>y>>z;
    cout<<"Minimum Steps : "<<cellMito(n,x,y,z)<<endl;
}