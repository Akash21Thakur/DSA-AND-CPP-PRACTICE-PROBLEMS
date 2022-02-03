#include <bits/stdc++.h>
using namespace std;

// Link : https://practice.geeksforgeeks.org/problems/minimize-the-heights3351/1

// algo:
// 1. sort the array
// 2. min(max diff) ans = last-first(say)
// 3. check for every value by inc/dec if range change
//     -> if so update the ans
// for more detail ->sksama

class Solution
{
public:
    int getMinDiff(int arr[], int n, int k)
    {

        sort(arr, arr + n);

        int result = arr[n - 1] - arr[0];
        int maxi, mini;

        for (int i = 1; i < n; i++)
        {
            // a[i]->y
            // a[i-1]->x
            if (arr[i] - k >= 0)
            {
                maxi = max(arr[i - 1] + k, arr[n - 1] - k);
                mini = min(arr[0] + k, arr[i] - k);

                result = min(result, maxi - mini);
            }
        }
        return result;
    }
};