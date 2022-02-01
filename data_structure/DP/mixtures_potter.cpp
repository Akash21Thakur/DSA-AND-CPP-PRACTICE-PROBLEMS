#include <iostream>
#include <climits>
using namespace std;

int a[1000];
int dp[100][100];

int sum(int s, int e)
{
    int ans = 0;
    for (int i = s; i <= e; i++)
    {
        ans += a[i];
        ans %= 100;
    }
    return ans;
}

int minGas(int i, int j)
{
    if (i >= j)
        return 0;

    // lookup
    if (dp[i][j] != -1)
        return dp[i][j];

    dp[i][j] = INT_MAX;
    for (int k = i; k <= j; k++)
    {
        dp[i][j] = min(dp[i][j], (minGas(i, k) + minGas(k + 1, j) + sum(i, k) * sum(k + 1, j)));
    }

    return dp[i][j];
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            dp[i][j] = -1;
        }
    }
    cout << "Minimum Gas Produced : " << minGas(0, n - 1) << endl;
}