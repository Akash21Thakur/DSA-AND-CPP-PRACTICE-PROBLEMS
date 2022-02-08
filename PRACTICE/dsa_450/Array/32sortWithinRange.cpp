#include <bits/stdc++.h>
using namespace std;

// prob_link : https://practice.geeksforgeeks.org/problems/three-way-partitioning/1#

// METHOD-1  O(nlogn)
//  simply sort

// METHOD-2   --> Time : O(n) , Space : O(1)
// idea is similar to DNF SORTING
class Solution
{
public:
    // Function to partition the array around the range such
    // that array is divided into three parts.
    void threeWayPartition(vector<int> &ar, int a, int b)
    {
        int n = ar.size();
        int i = 0;
        int j = n - 1;
        int k = 0;

        while (k <= j)
        {
            if (ar[k] < a)
            {
                swap(ar[k], ar[i]);
                i++;
                k++;
            }
            else if (ar[k] > b)
            {
                swap(ar[k], ar[j]);
                j--;
            }
            else
                k++;
        }
    }
};