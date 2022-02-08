#include <bits/stdc++.h>
using namespace std;

// prob_link : https://practice.geeksforgeeks.org/problems/minimum-swaps-required-to-bring-all-elements-less-than-or-equal-to-k-together4847/1

// METHOD-1  Time : O(n^2) , Space : O(1)
// search in all the subarray of size "good element"  and return the minimum one

// METHOD-2  Time : O(n) , O(1)
// SLIDING WINDOW TECHNIQUE

int minSwap(int a[], int n, int k)
{
    // finding the window size
    // number of good = window size
    int window = 0;
    for (int i = 0; i < n; i++)
        if (a[i] <= k)
            window++;

    // Bad values in First Window
    int bad = 0;
    for (int i = 0; i < window; i++)
    {
        if (a[i] > k)
            bad++;
    }

    int ans = bad;
    int i = 0, j = window;
    while (j < n)
    {
        if (a[i] > k)
            bad--;
        if (a[j] > k)
            bad++;

        i++;
        j++;

        ans = min(ans, bad);
    }
    return ans;
}