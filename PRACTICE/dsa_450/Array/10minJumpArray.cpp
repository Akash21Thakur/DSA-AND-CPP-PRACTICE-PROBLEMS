#include <bits/stdc++.h>
using namespace std;

// prob_link : https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1
// for ref :  CODE LIBRARY

// Time : O(n) , Space : O(1)
int minJumpOptimized(int *a, int n)
{
    int maxReach = a[0];
    int step = a[0];
    int jump = 1;

    if (n == 1)
        return 0;
    else if (a[0] == 0)
        return -1;
    else
    {
        for (int i = 1; i < n; i++)
        {
            if (i == n - 1)
                return jump;

            maxReach = max(maxReach, i + a[i]); // max reachable point
            step--;

            if (step == 0)
            {
                jump++;
                if (i >= maxReach) // can't jump to i
                    return -1;

                step = maxReach - i;
            }
        }
    }
}

// dp-bottom-up -->Time : O(n^2) , Space : O(n)
// to check how many ways are there to reach ith place ans store the minimum of these
int minJumpBotUp(int *a, int n)
{
    int dp[n];

    for (int i = 0; i < n; i++)
        dp[i] = INT_MAX;

    dp[0] = 0;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (dp[j] != INT_MAX and (a[j] + j) >= i)
            {
                if (dp[j] + 1 < dp[i])
                {
                    dp[i] = dp[j] + 1;
                }
            }
        }
    }

    if (dp[n - 1] != INT_MAX)
        return dp[n - 1];
    return -1;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << "Jumps : " << minJumpBotUp(a, n) << endl;
    cout << "Jump optimized : " << minJumpOptimized(a, n) << endl;
}
