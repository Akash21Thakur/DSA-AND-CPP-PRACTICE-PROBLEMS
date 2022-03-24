// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    string findSubString(string str)
    {
        unordered_map<char,int> mp;
        set<char> s;
        int len=str.length();
        
        for(int i=0;i<len;i++)  s.insert(str[i]);
        int n=s.size();
        int count=0;
        int i=0,j=1;
        mp[str[0]]++;
        count++;
        int ans=INT_MAX;
        int ansIdx=0;
        while(j<len and i<=j)
        {
            if(count<n)
            {
                if(mp[str[j]]==0)   count++;
                mp[str[j]]++;
                j++;
            }
            else if(count==n)
            {
                if(ans>j-i)
                {
                    ansIdx=i;
                    ans=j-i;
                }
                // ans=min(ans,j-i);
                if(mp[str[i]]==1)   count--;
                mp[str[i]]--;
                i++;
            }
        }
        while(count==n)
        {
            if(ans>j-i)
                {
                    ansIdx=i;
                    ans=j-i;
                }
                if(mp[str[i]]==1)   count--;
                mp[str[i]]--;
                i++;
        }
        // cout<<ans<<str.substr(ansIdx,ans)<<endl;
        return str.substr(ansIdx,ans);
    }
};

// { Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str).size() << endl;
    }
    return 0;
}  // } Driver Code Ends