#include<bits/stdc++.h>
using namespace std;

// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
    
public:
    int wordBreak(string s, vector<string> &B) {
        if(B.size()==0)   return false;
        
        //code here
        vector<bool> dp(s.size()+1,false);
        dp[0]=true;
        
        for(int i=1;i<=s.size();i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                //if substr till i has been found or not...
                if(dp[j])
                {
                    string word=s.substr(j,i-j);
                    
                    if(find(B.begin(),B.end(),word)!=B.end())
                      {dp[i]=true;
                      break;}
                      
                }
            }
        }
        return dp[s.size()];
    }
};

// { Driver Code Starts.

int main(){
  
        int n;
        cout<<"Enter size of dictionary : ";
        cin>>n;
        vector<string> dict;
        cout<<"Enter "<<n<<" words : ";
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cout<<"Word to be searched :";
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }

  // } Driver Code Ends