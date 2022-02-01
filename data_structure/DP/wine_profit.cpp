#include<iostream>
using namespace std;

int recSoln(int *a,int s,int e,int y)
{
    if(s>e)
      return 0;

    int start=a[s]*y + recSoln(a,s+1,e,y+1);
    int end=a[e]*y+recSoln(a,s,e-1,y+1);

    return max(start,end);  

}

int topDown(int *wine,int s,int e,int y,int dp[][100])
{
    if(s>e)  return 0;

    if(dp[s][e]!=0)   return dp[s][e];

    int ans1=wine[s]*y + topDown(wine,s+1,e,y+1,dp);
    int ans2=wine[e]*y + topDown(wine,s,e-1,y+1,dp);

    return dp[s][e]=max(ans1,ans2);
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
       cin>>a[i];
       int s=0,e=n-1,y=1;

    cout<<"Profit : "   <<recSoln(a,s,e,y)<<endl;

    int dp[100][100]={0};
    s=0,e=n-1,y=1;
    cout<<"Top Down : "<<topDown(a,s,e,y,dp)<<endl;

}