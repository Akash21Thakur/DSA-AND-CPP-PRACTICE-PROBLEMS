#include <iostream>
#include <climits>
using namespace std;

int topDown(int n, int *dp)
{
    if (n == 1)
        return 0;
    if (dp[n] != 0)
        return dp[n];
    int op1 = INT_MAX, op2 = INT_MAX, op3 = INT_MAX;
    if (n % 3 == 0)
        op1 = topDown(n / 3, dp);
    if (n % 2 == 0)
        op2 = topDown(n / 2, dp);
    op3 = topDown(n - 1, dp);

    return dp[n] = (min(min(op1, op2), op3) + 1);
}

int bottomUp(int n)
{
    int dp[n + 1] = {0};
    dp[1] = {0}; // base case

    for (int i = 2; i <= n; i++)
    {
        int op1, op2, op3;
        op1 = op2 = op3 = INT_MAX;
        if (i % 3 == 0)
            op1 = dp[i / 3];
        if (i % 2 == 0)
            op2 = dp[i / 2];
        op3 = dp[i - 1];

        dp[i] = min(min(op1, op2), op3) + 1;
    }
    return dp[n];
}

int main()
{
    int n;
    cout << "Enter the number : ";
    cin >> n;
    int dp[n + 1] = {0};

    cout << "Top-Down : " << topDown(n, dp) << endl;
    cout << "Bottom-Up : " << bottomUp(n) << endl;
}