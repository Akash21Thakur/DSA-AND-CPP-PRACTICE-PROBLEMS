//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int helper(vector<int> &dp, int n, int x, int y, int z)
    {
        if (n == 0)
            return 0;

        if (dp[n] != -1)
            return dp[n];

        int a(INT_MIN), b(INT_MIN), c(INT_MIN); // intialize
        if (x <= n)
            a = helper(dp, n - x, x, y, z);
        if (y <= n)
            b = helper(dp, n - y, x, y, z);
        if (z <= n)
            c = helper(dp, n - z, x, y, z);

        return dp[n] = max({a, b, c}) + 1;
    }

    // Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        vector<int> dp(n + 1, -1);
        helper(dp, n, x, y, z);
        return dp[n] < 0 ? 0 : dp[n];
    }
};

//{ Driver Code Starts.
int main()
{

    // taking testcases
    int t;
    cin >> t;
    while (t--)
    {
        // taking length of line segment
        int n;
        cin >> n;

        // taking types of segments
        int x, y, z;
        cin >> x >> y >> z;
        Solution obj;
        // calling function maximizeTheCuts()
        cout << obj.maximizeTheCuts(n, x, y, z) << endl;
    }

    return 0;
}
// } Driver Code Ends