// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    bool ifSumPresent(int *a, int idx, int target, vector<vector<int>> &dp)
    {
        if (target == 0)
            return true;
        if (idx == 0)
            return a[0] == target;

        if (dp[idx][target] != -1)
            return dp[idx][target];

        // node include
        bool notTake = ifSumPresent(a, idx - 1, target, dp);
        bool take = false;
        if (target >= a[idx])
            take = ifSumPresent(a, idx - 1, target - a[idx], dp);

        return dp[idx][target] = notTake or take;
    }

    int equalPartition(int N, int arr[])
    {
        int sum = 0;
        for (int i = 0; i < N; i++)
            sum += arr[i];

        // if odd ...answer not possible
        if (sum & 1)
            return 0;

        // check if sum/2(target) exist in the array
        int target = sum / 2;
        vector<vector<int>> dp(N + 1, vector<int>(target + 1, -1));

        return ifSumPresent(arr, N - 1, target, dp);
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        if (ob.equalPartition(N, arr))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
} // } Driver Code Ends