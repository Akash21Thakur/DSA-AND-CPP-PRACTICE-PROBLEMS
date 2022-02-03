#include <bits/stdc++.h>
using namespace std;

// best - KADANE'S ALGORITHM -O(n)
// algo :
//  1. curSum+=a[i];
//  2. ans=max(curSum,ans)
//  3. curSum=max(curSum,0)

#define ll long long int

ll kadanesAlgo(vector<int> &nums)
{
    ll maxSum = INT_MIN;
    ll curSum = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        curSum += nums[i];
        maxSum = max(curSum, maxSum);
        curSum = max(0ll, curSum); // ignore if negative
    }
    return maxSum;
}