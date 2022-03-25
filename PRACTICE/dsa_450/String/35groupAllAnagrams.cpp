// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        unordered_map<string,vector<string>> mp;
        // unordered_map<string,vector<string>> mp;
        int n=string_list.size();
        for(int i=0;i<n;i++)
        {
            string temp=string_list[i];
            sort(temp.begin(),temp.end());
            mp[temp].push_back(string_list[i]);
        }
        
        vector<vector<string>> ans;
        int m=mp.size();
        // auto it=mp.begin();
        // for(int i=0;i<m;i++)
        // {
        //     for(string str:mp[i])
        //     ans[i].push_back(str);
        // }
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            ans.push_back(mp[it->first]);
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
        int n;
        cin>>n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin>>string_list[i]; 
        Solution ob;
        vector<vector<string> > result = ob.Anagrams(string_list);
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for(int j=0; j < result[i].size(); j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}
  // } Driver Code Ends