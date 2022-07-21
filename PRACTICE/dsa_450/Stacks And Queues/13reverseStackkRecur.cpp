//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    vector<int> ans;
    void helper(stack<int> st)
    {
        if (st.empty())
            return;

        ans.push_back(st.top());
        st.pop();
        helper(st);
    }
    vector<int> Reverse(stack<int> St)
    {
        helper(St);
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        stack<int> St;
        for (int i = 0; i < N; i++)
        {
            int x;
            cin >> x;
            St.push(x);
        }
        Solution ob;
        vector<int> ans = ob.Reverse(St);
        for (int i = 0; i < N; i++)
        {
            cout << ans[i];
            if (i != N - 1)
                cout << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends