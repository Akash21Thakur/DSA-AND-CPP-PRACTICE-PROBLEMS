// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
	{
	//method-1 ...naive 3 loop solution
	// current one ---> n^2
	public:
	long long countTriplets(long long arr[], int n, long long sum)
	{
	   // i<j<k is just to make confusion...it does not affect the final answer
	    sort(arr,arr+n);
	    long long int ans=0;
	    for(int i=0;i<n-2;i++)
	    {
	        int j=i+1,k=n-1;
	        while(j<k)
	        {
	            if(arr[i]+arr[j]+arr[k]>=sum)
	               k--;
	               else
	               {
	                   ans+=k-j;
	                   j++;
	               }
	        }
	    }
	    return ans;
	}
		 

};

// { Driver Code Starts.

int main() 
{
  
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
    	long long sum;
        cin>>n>>sum;
        long long arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
	    

       

        Solution ob;
        cout << ob.countTriplets(arr, n, sum) ;
	   
        
	    cout << "\n";
	     
    }
    return 0;
}

     // } Driver Code Ends