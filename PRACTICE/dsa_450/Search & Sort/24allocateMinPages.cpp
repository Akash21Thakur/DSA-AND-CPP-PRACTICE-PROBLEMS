// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    
    bool isAllocated(int *a,int n,int m,int barrier)
    {
        int count=1,pages=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]>barrier)   return false;
            if(a[i]+pages>barrier)
            {
                count++; //new student
                pages=a[i];
            }
            else
              pages+=a[i];
        }
        if(count>m)   return false;
        return true;
    }
    
    //Time: nlogn
    //ref: Striver 
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        int sum=0;
        for(int i=0;i<N;i++)
            sum+=A[i];

        // search space for Binary search
        int low=A[0],high=sum;
        int res;
        
        while(low<=high)
        {
            int mid=(low+high)/2;
            
            //minimum is in the 1st half
            if(isAllocated(A,N,M,mid))
            {
                res=mid;
                high=mid-1;
            }
            // need to increase the barrier...2nd half
            else
               low=mid+1;
        }
        return res;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends