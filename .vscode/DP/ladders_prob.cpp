#include <iostream>
using namespace std;

int laddersTopDown(int n, int k, int *dp)
{
    // base case
    if (n == 0)
        return 1;

    // look-up
    if (dp[n] != 0)
        return dp[n];

    // rec case
    int ways = 0;
    for (int i = 1; i <= k; i++)
    {
        if (n - i >= 0)
            ways += laddersTopDown(n - i, k, dp);
    }

    return dp[n] = ways;
}

int laddersBottomUp(int n, int k)
{
    int dp[100] = {0};
    dp[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (i - j >= 0)
                dp[i] += dp[i - j];
        }
    }
    return dp[n];
}

// bottom up optimized
// kinda sliding window
int laddersOptimized(int n, int k)
{
    int dp[100] = {0};
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= k; i++)
        dp[i] = 2 * dp[i - 1];

    for (int i = k + 1; i <= n; i++)
        dp[i] = 2 * dp[i - 1] - dp[i - k - 1];

    return dp[n];
}

int main()
{
    int n, k;
    cin >> n >> k;
    int dp[100] = {0};

    cout << "Ways is top down : " << laddersTopDown(n, k, dp) << endl;
    cout << "Ways is bottom up : " << laddersBottomUp(n, k) << endl;
    cout << "Optimized : " << laddersOptimized(n, k) << endl;
}