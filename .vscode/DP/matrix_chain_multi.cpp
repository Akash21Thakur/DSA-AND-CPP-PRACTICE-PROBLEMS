#include <iostream>
#include <cstring>
#include <climits>
using namespace std;

// int main()
// {
//     cout<<"akash thakur"<<endl;
// }
int MCM(int *a, int i, int j, int dp[][100])
{
    if (i >= j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];
    int ans = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int tempAns = MCM(a, i, k, dp) + MCM(a, k + 1, j, dp) + a[i - 1] * a[k] * a[j];
        ans = min(ans, tempAns);
    }

    return dp[i][j] = ans;
}

int main()
{
    int n;
    // cout<<"Akash"<<endl;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int dp[100][100];
    memset(dp, -1, sizeof(dp));

    cout << MCM(a, 1, n - 1, dp) << endl;
}