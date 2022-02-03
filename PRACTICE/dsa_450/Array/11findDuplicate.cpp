#include <bits/stdc++.h>
using namespace std;

// prob_link : https://leetcode.com/problems/find-the-duplicate-number/

// instinct
//  since values=[1, n] and one is the repeated...so we negate the value at ith index...
//  if it is already -ve means we found the repeated element

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int n = nums.size();
        int idx;
        for (int i = 0; i < n; i++)
        {
            idx = abs(nums[i]) - 1;
            if (nums[idx] < 0)
                break;
            nums[idx] *= -1;
        }

        return idx + 1;
    }
};