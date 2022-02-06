#include <bits/stdc++.h>
using namespace std;

// prob_link : https://practice.geeksforgeeks.org/problems/array-subset-of-another-array2317/1

// METHOD-1  Time : O(n^2) , Space : O(1)
// Simple...linear search for all the element of arr2 in arr1

// Method-2 :  Time : O(nlogn) , Space : O(1)
// Sort and the binary search

// METHOD-3   Time : O(n) , Space : O(n)
// using hashmap
string isSubset(int a1[], int a2[], int n, int m)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
        mp[a1[i]]++;

    for (int i = 0; i < m; i++)
    {
        if (mp[a2[i]] == 0)
            return "No";
    }
    return "Yes";
}