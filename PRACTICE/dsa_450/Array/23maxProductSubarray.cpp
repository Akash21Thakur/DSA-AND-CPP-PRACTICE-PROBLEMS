#include <bits/stdc++.h>
using namespace std;

// prob_link : https://practice.geeksforgeeks.org/problems/maximum-product-subarray3604/1#

// METHOD-1  -->o(N^2)
// CHECK FOR ALL THE SUBARRAY

// METHOD-2  --O(N)
// keep track of current mini,maxi and update the answer accordingly
// help : CODE LIBRARY

long long maxProduct(vector<int> a, int n)
{
    long long int ans, maxi, mini;
    maxi = mini = ans = a[0];

    for (int i = 1; i < n; i++)
    {
        if (a[i] < 0)
            swap(maxi, mini);

        maxi = max<long long>(a[i], maxi * a[i]);
        mini = min<long long>(a[i], mini * a[i]);

        ans = max(maxi, ans);
    }
    return ans;
}