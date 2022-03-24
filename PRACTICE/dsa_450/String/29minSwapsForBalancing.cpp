// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
//CODE LIBRARY AND GFG
    int minimumNumberOfSwaps(string S){
        // //METHOD-1 SPACE: O(N)
        // vector<int> openidx;
        // int n=S.length();
        // for(int i=0;i<n;i++)
        //   if(S[i]=='[')  openidx.push_back(i);
           
        // int idx=0;  //itr for vector
        // int ans=0,count=0;
        // for(int i=0;i<n;i++)
        // {
        //     if(S[i]=='[')
        //     {
        //         count++;
        //         idx++;
        //     }
        //     else
        //     {
        //         count--;
        //         if(count<0){
        //             ans+=openidx[idx]-i;
        //             swap(S[i],S[openidx[idx]]);
        //             idx++;
        //             count=1;
        //         }
        //     }
        // }
        // return ans;
        
        // ..METHOD-2 SPACE: O(n)
        int open=0,close=0,fault=0,ans=0;
        int n=S.length();
        for(int i=0;i<n;i++)
        {
            if(S[i]==']')
            {
                close++;
                fault=close-open;
            }
            else
            {
                open++;
                if(fault>0)
                {
                    ans+=fault;
                    fault--;
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
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.minimumNumberOfSwaps(S) << endl;
    }
    return 0; 
}   // } Driver Code Ends