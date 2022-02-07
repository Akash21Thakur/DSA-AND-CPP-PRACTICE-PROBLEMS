#include <bits/stdc++.h>
using namespace std;

// prob_link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
// help_link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/discuss/1523723/C%2B%2B-or-Four-Solutions-%3A-Recursion-Memoization-DP-with-O(N)-space-DP-with-O(1)-Space

// explained well in the help link
class Solution
{

    int helper(vector<int> &prices, int day, int transactionLeft, vector<vector<int>> &memo)
    {
        if (day == prices.size())
            return 0;
        if (transactionLeft == 0)
            return 0;

        int &ans = memo[day][transactionLeft];
        if (ans != -1) // if already calculated
            return ans;

        // Skip
        int ans1 = helper(prices, day + 1, transactionLeft, memo);

        // BUY/SELL
        int ans2 = 0;

        // 1-2-3-4   ---> sell-buy-sell-buy
        bool buy = (transactionLeft % 2 == 0);

        if (buy) // BUY
        {
            ans2 = -prices[day] + helper(prices, day + 1, transactionLeft - 1, memo);
        }
        else // SELL
        {
            ans2 = prices[day] + helper(prices, day + 1, transactionLeft - 1, memo);
        }

        return ans = max(ans1, ans2);
    }

public:
    int maxProfit(vector<int> &prices)
    {
        vector<vector<int>> memo(prices.size(), vector<int>(5, -1));
        int ans = helper(prices, 0, 4, memo);
        return ans;
    }
};