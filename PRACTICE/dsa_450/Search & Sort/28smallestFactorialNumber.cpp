
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    //ref : Prateek's Solution
    int check(int mid,int n)
    {
        int ans=0;
            int p=5;
            while((mid/p)>0)
            {
                ans+=(mid/p);
                p*=5;
            }
            
            return ans>=n;
    }
    
    public:
        int findNum(int n)
        {
            //occurence of 5 or its powers gives the numebr of trailing zeros
            //the ans lies b/w 0---5*n
            //performing binary search
            if(n==1)
               return 5;
               
            int low=0,high=5*n;
            
            while(low<high)
            {
                int mid=(low+high)>>1;
                if(check(mid,n))
                  high=mid;
                else
                  low=mid+1;
            }
            
            return low;
            
        }
};

// { Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Solution ob;
        cout <<ob.findNum(n) << endl;
    }
return 0;
}  // } Driver Code Ends