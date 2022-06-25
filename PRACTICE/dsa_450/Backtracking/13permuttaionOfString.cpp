// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    void helper(string s, vector<string> &ans, int idx)
    {
        if (idx >= s.length())
        {
            ans.push_back(s);
            return;
        }
        // try dry run in copy for better understanding
        for (int i = 0; i <= idx; i++)
        {
            swap(s[i], s[idx]);
            helper(s, ans, idx + 1);
            // backtracking
            swap(s[i], s[idx]);
        }
    }

public:
    vector<string> find_permutation(string S)
    {
        vector<string> ans;
        helper(S, ans, 0);
        //  sort(ans.begin(),ans.end());     //earlier version...when the values were not repeated
        map<string, int> mp; // to store total unique values
        for (int i = 0; i < ans.size(); i++)
            mp[ans[i]]++;
        vector<string> s;
        // return the key as they are the unique answers
        for (auto x : mp)
            s.push_back(x.first);
        return s;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.find_permutation(S);
        for (auto i : ans)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends