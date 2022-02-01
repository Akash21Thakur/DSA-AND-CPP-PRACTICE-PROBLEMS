#include <iostream>
using namespace std;

// RECURSIVE APPROACH
int recFibo(int n)
{
    if (n == 0 or n == 1)
        return n;

    int ans = 0;
    ans = recFibo(n - 1) + recFibo(n - 2);
    return ans;
}

// TOP-BOTTOM APPROACH
int topDownFibo(int n, int *dp)
{
    if (n == 0 or n == 1)
        return n;

    if (dp[n] != 0)
        return dp[n];

    int ans;
    ans = topDownFibo(n - 1, dp) + topDownFibo(n - 2, dp);

    return dp[n] = ans;
}

// BOTTOM UP APPROACH
int botUpFibo(int n, int *dp)
{
    if (n == 0 or n == 1)
        return n;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

// BOTTOM UP - SPACE OPTIMIZED
int fiboBest(int n)
{
    
    int a = 0, b = 1, ans = 0;
    // cout << "Akash"
    //      << " ";

    for (int i = 2; i <= n; i++)
    {
        ans = a + b;
        a = b;
        // cout<<"Check ";
        b = ans;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    int dp1[n + 1] = {0};
    int dp2[] = {0};
    
    cout << fiboBest(n) << endl;
    cout << recFibo(n) << endl;
    cout << topDownFibo(n, dp1) << endl;
    cout << botUpFibo(n, dp2) << endl;
    
}