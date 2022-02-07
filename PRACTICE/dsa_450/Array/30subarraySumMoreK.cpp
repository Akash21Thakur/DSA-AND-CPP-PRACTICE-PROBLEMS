#include <bits/stdc++.h>
using namespace std;

// prob_link : https://leetcode.com/problems/minimum-size-subarray-sum/

// The O(n) solution is to use two pointers: l and r.
//  First we move r until we get a sum >= s, then we move l to the right until sum < s.
//   In this process, store the minimum length between l and r. Since each element in nums will be visited by l and r for at most once.
//   This algorithm is of O(n) time.

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int l = 0, r = 0, sum = 0, len = INT_MAX;
        int n = nums.size();
        while (r < n)
        {
            sum += nums[r++];
            while (sum >= target)
            {
                len = min(len, r - l);
                sum -= nums[l++];
            }
        }
        return len == INT_MAX ? 0 : len;
    }
};