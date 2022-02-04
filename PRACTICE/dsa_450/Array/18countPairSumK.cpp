#include <bits/stdc++.h>
using namespace std;

// prob_link : https://practice.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1

// Method-1 -->O(n^2)
// naive approach : simple search for every possible pair

// Method-2  --> Time : O(n) , Space : O(n)
// algo:
// simple just use map to store element count
// try in copy for better understanding
int getPairsCount(int arr[], int n, int k)
{
    map<int, int> mp;

    for (int i = 0; i < n; i++)
        mp[arr[i]]++;

    // count will be double the answer as every pair will be considered twice
    int twicecount = 0;

    for (int i = 0; i < n; i++)
    {
        twicecount += mp[k - arr[i]];

        if (k - arr[i] == arr[i]) // ignore pairing with itself
            twicecount--;
    }

    return twicecount / 2;
}