#include <bits/stdc++.h>
using namespace std;

// Problem:  Find maximal survival time...while switching b/w fire, water, air
// Algo:  Dp
//   -->reach one of the two possible jump other than the current standing
//    --> check for all the possibility and return the best max. one
int dp[1005][1005];

int maxSurvival(int h, int a, int pos)
{
    if (h <= 0 or a <= 0)
        return 0;

    if (dp[h][a] != -1)
        return dp[h][a];

    int x = 0, y = 0, z = 0;
    if (pos != 1)
        x = 1 + maxSurvival(h + 3, a + 2, 1);
    if (pos != 2)
        y = 1 + maxSurvival(h - 5, a - 10, 2);
    if (pos != 3)
        z = 1 + maxSurvival(h - 20, a + 5, 3);

    return dp[h][a] = max({x, y, z});
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int health, armor;
        cin >> health >> armor;

        memset(dp, -1, sizeof(dp));
        // 1--> Air,2-->water, 3-->fire
        cout << max({maxSurvival(health + 3, armor + 2, 1), maxSurvival(health - 5, armor - 10, 2), maxSurvival(health - 20, armor + 5, 3)}) << endl;
    }
}
