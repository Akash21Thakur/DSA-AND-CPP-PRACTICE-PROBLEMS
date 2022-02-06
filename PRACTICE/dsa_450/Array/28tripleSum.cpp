#include <bits/stdc++.h>
using namespace std;

// prob_link : https://practice.geeksforgeeks.org/problems/triplet-sum-in-array-1587115621/1#

// O( nlogn +n^2 )
// Sort...and find the target by summing three values

// Function to find if there exists a triplet in the
// array A[] which sums up to X.
bool find3Numbers(int a[], int n, int X)
{
    sort(a, a + n);
    for (int i = 0; i < n; i++)
    {
        int toFind = X - a[i];
        int j = i + 1;
        int k = n - 1;

        while (j < k)
        {
            int sum = a[j] + a[k];

            if (sum == toFind)
                return true;
            else if (sum > toFind)
                k--;
            else
                j++;
        }
    }

    return false;
}