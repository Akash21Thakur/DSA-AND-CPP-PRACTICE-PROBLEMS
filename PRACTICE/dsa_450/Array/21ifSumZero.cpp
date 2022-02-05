#include <bits/stdc++.h>
using namespace std;

// prob_link : https://practice.geeksforgeeks.org/problems/subarray-with-0-sum-1587115621/1

// MEHTOD-1 Time : O(n^2) , Space : O(1)
//  check for all subarray sum

// Method-2 Time : O(n) , Space : O(n)
// using hashmap(STORES commulative sun) check if
//   --> commulative sum appeared more thna one(means middle element made sum =0 )
//   --> commulative sum is equal to zero
//   --> a[i]==0
//   than "YES"    else "NO"
bool subArrayExists(int a[], int n)
{
    // method-1
    //  for(int i=0;i<n;i++)
    //  {
    //      int sum=0;
    //      for(int j=i;j<n;j++)
    //       {
    //           sum+=a[j];
    //           if(sum==0)   return true;
    //       }
    //  }
    //  return false;

    // method-2
    unordered_map<int, int> map;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        if (map[sum] or sum == 0 or a[i] == 0)
            return true;
        else
            map[sum] = 1;
    }
    return false;
}