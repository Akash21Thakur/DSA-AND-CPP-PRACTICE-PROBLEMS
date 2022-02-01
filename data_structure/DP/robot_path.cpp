#include <iostream>
#include <cstring>
using namespace std;

#define mod 1000000007
int dp[1001][1001];

int numWays(int m, int n)
{
    if (dp[0][0] == -1)
        return 0;

    for (int i = 0; i < n; i++)
    {
        if (dp[0][i] == -1)
            break;
        dp[0][i] = 1;
    }

    for (int i = 0; i < m; i++)
    {
        if (dp[i][0] == -1)
            break;
        dp[i][0] = 1;
    }

    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (dp[i][j] == -1)
                continue;

            dp[i][j] = 0;
            if (dp[i][j - 1] != -1)
                dp[i][j] = dp[i][j - 1] % mod;

            if (dp[i - 1][j] != -1)
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
        }
    }

    if (dp[m - 1][n - 1] == -1)
        return 0;

    return dp[m - 1][n - 1];
}

int main()
{
    memset(dp, 0, sizeof(dp));
    int m, n, p;
    cin >> m >> n >> p;
    for (int i = 0; i < p; i++)
    {
        int x, y;
        cin >> x >> y;
        dp[x - 1][y - 1] = -1;
    }

    cout << numWays(m, n) << endl;
}