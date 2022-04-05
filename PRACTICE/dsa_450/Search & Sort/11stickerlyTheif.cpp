// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    
    int helper(vector<int> &dp,int *arr,int idx)
    {
        if(idx==0)   return arr[idx];
        if(idx<0)    return 0;
        
        if(dp[idx]!=-1)   return dp[idx];
        
        int takemoney=helper(dp,arr,idx-2)+arr[idx];
        int skipmoney=helper(dp,arr,idx-1);
        
        return dp[idx]=max(takemoney,skipmoney);
        
        // return max(helper(sum,idx,a,n))
    }
    
    int FindMaxSum(int arr[], int n)
    {
        vector<int> dp(n+1,-1);
        int idx=n-1;
        return helper(dp,arr,idx);
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}
  // } Driver Code Ends