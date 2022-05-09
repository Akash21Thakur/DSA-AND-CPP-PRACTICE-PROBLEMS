// { Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/the-painters-partition-problem1535/1/#

 // } Driver Code Ends
//User function template for C++

//SIMILAR TO ALLOCATING MIN PAGES
class Solution
{
  public:
  bool check(int *v,int n,int k,int mid)
{
   long long int sum=0,count=1;
    for(int i=0;i<n;i++)
    {
        if(v[i]>mid)   return false;
        if(v[i]+sum<=mid)
        {
            sum+=v[i];
            
        }
        else
        {
            count++;
            if(count>k )   return false;
            sum=v[i];
            
        }
        // sum+=v[i];
        // if(sum>mid)
        // {
            
        // }
    }
//   if(count>k)  return false;
  return true;
}
    long long minTime(int v[], int n, int k)
    {
       long long int low=0,high=0;
    for(int i=0;i<n;i++)
    {
        // low=max(low,v[i]);
        high+=v[i];
    }
    long long int res;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(check(v,n,k,mid))
        {
            res=mid;
            high=mid-1;

        }
        else
        low=mid+1;


    }
    return res;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}  // } Driver Code Ends