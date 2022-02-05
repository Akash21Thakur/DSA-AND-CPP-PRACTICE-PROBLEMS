#include <bits/stdc++.h>
using namespace std;

// prob_link-1 easy(n/2) : https://leetcode.com/problems/majority-element/
// prob_link-1 medium(n/3) : https://leetcode.com/problems/majority-element-ii/

// METHOD-1  Time : O(n^2) , Space : O(1)
// traverse for all the elemnt and check if its count is greater than the limit

// METHOD-2  Time : O(nlogn) , Space : O(n)
// use hashmap and store the count...print the one with count>_LIMITS_H

// METHOD-3  Time : O(n) , Space : O(1)
// Boyer-Moore Majority Vote Algorithm
// -->Striver Video For Details

//  ------------------------MAJORITY ELEMENT - I ------------------------------
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        // METHOD-1

        // sort(nums.begin(),nums.end());
        // return nums[nums.size()/2];

        int count = 0;
        int candidate = 0;

        for (int num : nums)
        {
            if (count == 0)
            {
                candidate = num;
                count++;
            }
            else if (num == candidate)
                count += 1;
            else
                count -= 1;
        }
        return candidate;
    }
};

//  ------------------------MAJORITY ELEMENT - II ------------------------------
vector<int> majorityElement(vector<int> &nums)
{
    // support variables
    int cand1, vote1 = 0, cand2, vote2 = 0, lmt = nums.size() / 3;
    // looking for the 2 most frequent items
    for (int n : nums)
    {
        if (n == cand1)
            vote1++;
        else if (n == cand2)
            vote2++;
        else if (!vote1)
        {
            cand1 = n;
            vote1++;
        }
        else if (!vote2)
        {
            cand2 = n;
            vote2++;
        }
        else
        {
            vote1--;
            vote2--;
        }
    }
    // checking the actual frequency of the 2 most common items
    vote1 = 0;
    vote2 = 0;
    for (int n : nums)
    {
        if (n == cand1)
            vote1++;
        if (n == cand2)
            vote2++;
    }

    // add to ans if count>limit
    vector<int> ans;
    if (vote1 > lmt)
        ans.push_back(cand1);
    if (vote2 > lmt)
        ans.push_back(cand2);

    return ans;
}