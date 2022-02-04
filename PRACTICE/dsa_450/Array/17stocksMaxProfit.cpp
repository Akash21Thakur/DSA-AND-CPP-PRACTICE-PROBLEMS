#include <bits/stdc++.h>
using namespace std;

// prob_link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

// algo
//  1. when less the --> update the current minimum always
//  2. when greater  --> update ans (if needed by comparing)

class Solution
{
    // ..strivers and  its a simple thinking problem
public:
    int maxProfit(vector<int> &prices)
    {
        int ans = 0;
        int curmin = prices[0];
        int n = prices.size();

        for (int i = 1; i < n; i++)
        {
            if (prices[i] < curmin)
                curmin = prices[i];
            else if (prices[i] > curmin)
                ans = max(ans, prices[i] - curmin);
        }

        return ans;
    }
};