#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        // minHeap
        priority_queue<int, vector<int>, greater<int>> pq;

        // push the first k element from the array
        for (int i = 0; i < k; i++)
            pq.push(nums[i]);

        // traverse the rest...if top is less than the current...pop and push the current
        for (int i = k; i < nums.size(); i++)
        {
            if (pq.top() < nums[i])
            {
                pq.pop();
                pq.push(nums[i]);
            }
        }

        // the top is the kth largest...as it is a minHeap
        return pq.top();
    }
};