#include <bits/stdc++.h>
using namespace std;

// prob_link : https://practice.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1

// sort and search for minimum diffrence comparing with every possible (i,i+m) value
long long findMinDiff(vector<long long> a, long long n, long long m)
{
    // code

    sort(a.begin(), a.end());
    long long int ans = INT_MAX;
    int k = m - 1;
    int i = 0;
    while (k < n)
    {
        ans = min(ans, a[k] - a[i]);
        i++;
        k++;
    }
    return ans;
}