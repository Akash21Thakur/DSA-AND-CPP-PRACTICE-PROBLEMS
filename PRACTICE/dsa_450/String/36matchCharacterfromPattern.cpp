// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        unordered_map<char,int> mp;
        
        
        for(int i=0;i<p.length();i++)
           mp[p[i]]++;
        
        int count=mp.size();   //distinct characters
        int i=0,j=0;
        
        int n=s.length();
        
        //for ans substring
        int start=0;
        int len=s.length();
        
        while(j<n)
        {
            if(mp.find(s[j])!=mp.end())
            {
                mp[s[j]]--;
                if(mp[s[j]]==0)
                   count--;
            }
            
                
                 while(count==0)//when all the charcter match
                 {
                     if(len>j-i+1)
                     {
                         len=j-i+1;
                         start=i;
                     }
                     
                     if(mp.find(s[i])!=mp.end()) //shrink
                     {
                         mp[s[i]]++;
                         if(mp[s[i]]==1)//if the chracter in s...increases and the matching chracters is out of s
                             count++;
                     }
                     i++;
                 }
                 j++;
        }
        
        //if the len does not change means all character from pattern not found
        return len==n ? "-1":s.substr(start,len);   
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
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends