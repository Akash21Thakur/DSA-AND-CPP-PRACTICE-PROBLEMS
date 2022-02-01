#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int maxSub(int n, int *a)
{
    int dp[n] = {};

    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (a[j] < a[i])
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    int maxi = dp[0];
    for (int i = 1; i < n; i++)
        maxi = max(maxi, dp[i]);
    return maxi;
}

// method-2
int meth2(int n, int *a)
{
    int dp[n + 2];
    dp[0] = INT_MIN;
    for (int i = 1; i <= n; i++)
        dp[i] = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        for (int len = 0; len < n; len++)
        {
            if (a[i] > dp[len] and a[i] < dp[len + 1])
            {
                dp[len + 1] = a[i];
                // break;
            }
        }
    }
    int maxi = 0;
    for (int i = 1; i <= n; i++)
    {
        if (dp[i] != INT_MAX)
        {
            maxi = i;
            cout << dp[i] << " ";
        }
    }
    return maxi;
}

// method-3
int meth3(int n, int *a)
{
    int dp[n + 1];
    dp[0] = INT_MIN;
    for (int i = 1; i <= n; i++)
        dp[i] = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        int idx = upper_bound(dp, dp + n + 1, a[i]) - dp;
        if (a[i] > dp[idx - 1] and a[i] < dp[idx])
            dp[idx] = a[i];
    }
    int maxi = 0;
    for (int i = n; i >= 0; i--)
    {
        if (dp[i] != INT_MAX)
        {
            maxi = i;
            // cout << dp[i] << " ";
            break;
        }
    }
    return maxi;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << "Length of max subsequence : " << maxSub(n, a) << endl;
    cout << "Method-2 : " << meth2(n, a) << endl;
    cout << "Dp-Binary : " << meth3(n, a) << endl;
}