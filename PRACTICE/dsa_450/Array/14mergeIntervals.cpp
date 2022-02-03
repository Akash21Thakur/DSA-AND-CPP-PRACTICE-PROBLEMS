#include <bits/stdc++.h>
using namespace std;

// prob_link : https://leetcode.com/problems/merge-intervals/submissions/

class Solution
{
    // simple sort compare and update...if no overlapping ...move to next range
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        int n = intervals.size();
        if (n == 1)
            return intervals;

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        int i = 0, j = 1;

        for (; j < n; j++)
        {
            if (ans[i][1] >= intervals[j][0])
                ans[i][1] = max(ans[i][1], intervals[j][1]);
            else
            {
                i++;
                ans.push_back(intervals[j]);
            }
        }
        return ans;
    }
};