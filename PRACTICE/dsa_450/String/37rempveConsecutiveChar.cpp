// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends

class Solution{
    public:
    string removeConsecutiveCharacter(string S)
    {
        string ans="";
        int n=S.length();
        int j=0;
        for(int i=0;i<n;i++)
        {
            
            while(S[i]==S[i+1] and i<n-1) //skip the duplicate
               i++;
            ans+=S[i]; //stores the required characters...no consecutive duplicate  
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
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.removeConsecutiveCharacter(s)<<endl;
    }
} 



  // } Driver Code Ends