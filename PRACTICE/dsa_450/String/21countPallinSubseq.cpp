#include<bits/stdc++.h>
using namespace std;

 

#define mod 1000000007
#define ll long long int

//CODE LIBRARY FOR REFERENCE

class Solution{
    ll helper(string &s,vector<vector<ll>> &dp,int i,int j)
    {
        if(i>j)   return 0;
        if(i==j)   return 1;
        
        if(dp[i][j]!=-1)   return dp[i][j];
        ll ans=0;
        if(s[i]==s[j])   ans=1+helper(s,dp,i+1,j)+helper(s,dp,i,j-1)%mod;
        else
        ans=helper(s,dp,i+1,j)+helper(s,dp,i,j-1)-helper(s,dp,i+1,j-1);
        return dp[i][j]=ans;
    }
    
    public:
    // /*You are required to complete below method */
    long long int  countPS(string str)
    {
      
      int n=str.length();
      vector<vector<ll>> dp(n+1,vector<ll>(n+1,-1));
      return helper(str,dp,0,n-1)%mod;
    }

     
};

// { Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}  // } Driver Code Ends