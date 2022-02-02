#include <iostream>
#include <vector>
#include <climits>
using namespace std;

#define ll long long int

// calculates sum for all the subarray and finds the max. along
// O(n^3)
ll naiveSumArray(vector<int> &nums)
{
    ll maxSum = INT_MIN;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            ll curSum = 0;
            for (int k = i; k <= j; k++)
                curSum += nums[k];
            maxSum = max(maxSum, curSum);
        }
    }
    return maxSum;
}

// better-one   Commulative Sum O(n^2)
// calculate the cSum before_hand reduces the extra inner looping in the above algo
ll cSum(vector<int> &nums)
{
    ll maxSum = INT_MIN;

    // // calculate cSum
    int n = nums.size();
    vector<int> csum;
    csum.push_back(nums[0]);

    for (int i = 1; i < n; i++)
        csum.push_back(csum[i - 1] + nums[i]);

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            ll curSum;
            if (i != 0)
                curSum = csum[j] - csum[i - 1];
            else
                curSum = csum[j];

            maxSum = max(curSum, maxSum);
        }
    }

    return maxSum;
}

// best - KADANE'S ALGORITHM -O(n)
// algo :
//  1. curSum+=a[i];
//  2. ans=max(curSum,ans)
//  3. curSum=max(curSum,0)

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

int main()
{
    int n, temp = 0;
    cout << "Size : ";
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        nums.push_back(temp);
    }
    // cout << nums.size() << endl;
    cout << "Naive : " << naiveSumArray(nums) << endl;
    cout << "CSum : " << cSum(nums) << endl;
    cout << "Kadanes : " << kadanesAlgo(nums) << endl;
}
