#include <iostream>
#include <climits>
using namespace std;

int minCoinsTopDown(int n, int *coins, int t, int *dp)
{
    if (n == 0)
        return 0;

    // ..LookUp
    if (dp[n] != 0)
        return dp[n];

    int ans = INT_MAX;
    for (int i = 0; i < t; i++)
    {
        if (n - coins[i] >= 0)
        {
            int temp = minCoinsTopDown(n - coins[i], coins, t, dp);
            ans = min(ans, temp + 1);
        }
    }

    return dp[n] = ans;
}

int minCoinsBottomUp(int n, int *coins, int t)
{
    // if (n == 0)
    //     return 0;

    int dp[n+1] = {0};
    int ans = INT_MAX;
    

    for (int i = 1; i <= n; i++)
    {
        dp[i] = INT_MAX;
        for (int j = 0; j < t; j++)
        {
            if ((i - coins[j]) >= 0)
            {
                int temp = dp[i - coins[j]];
                dp[i] = min(dp[i], temp + 1);
            }
        }
        // cout<<dp[i]<<" ";
    }
    cout <<endl;
    return dp[n];
}

int main()
{
    int n;
    cout << "Enter the number : ";
    cin >> n;
    int coins[] = {1, 7, 15};
    int dp[100] = {0};
    cout << "Bottom - UP : " << minCoinsBottomUp(n, coins, 3) << endl;
    cout << "Top - Down : " << minCoinsTopDown(n, coins, 3, dp) << endl;
    
}