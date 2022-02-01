#include <iostream>
#include <cstring>
using namespace std;

int mod = 10000007;
int dp[10000];

int frndPair(int n)
{
    if (n <= 2)
        return n;

    if (dp[n] != -1)
        return dp[n];
    int ans = frndPair(n - 1) % mod + (n - 1) * (frndPair(n - 2) % mod);
    // int single=frndPair(n-1)%mod;
    // int pair=(((n-1)%mod)*frndPair(n-2)%mod)%mod;
    // cout<<"akash";
    return dp[n] = ans;
}

int frndPairItr(int n)
{
    int dp[n + 1];
    memset(dp, -1, sizeof(dp));

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++)
    {
        dp[i] = dp[i - 1] + (i - 1) * dp[i - 2];
    }
    return dp[n];
}

int frndItrOpti(int n)
{
    if (n <= 2)
        return n;
    int a = 1, b = 2, c = 0;

    for (int i = 3; i <= n; i++)
    {
        c = b + (i - 1) * a;
        a = b;
        b = c;
    }
    return c;
}

int main()
{
    int n;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    cout << "Maximum Pairing : dp-rec  " << frndPair(n) << endl;
    cout << "dp-iterative : " << frndPairItr(n) << endl;
    cout << "dp-iterative space optimized : " << frndItrOpti(n) << endl;
}