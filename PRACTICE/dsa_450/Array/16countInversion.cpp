#include <bits/stdc++.h>
using namespace std;

// prob_link : https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1

// method -1  O(n^2)
//  search for every element i the number greater in (i+1,end)

// method-2 optimal
// Similar to merge sort -->O(nlogn)
long long int merge(long long int *a, int s, int mid, int e)
{
    long long int count = 0;
    int i = s, j = mid + 1, k = s;
    long long int temp[500000];

    while (i <= mid and j <= e)
    {
        if (a[i] <= a[j])
            temp[k++] = a[i++];
        else
        {
            count += mid - i + 1;
            temp[k++] = a[j++];
        }
    }

    while (i <= mid)
    {
        temp[k++] = a[i++];
    }

    while (j <= e)
    {
        temp[k++] = a[j++];
    }

    // merging into the original array
    for (int i = s; i <= e; i++)
    {
        a[i] = temp[i];
    }
    return count;
}

long long int helpermergesort(long long *a, long long int s, long long int e)
{
    if (s >= e)
        return 0;

    long long int mid = (s + e) / 2;

    long long int x = helpermergesort(a, s, mid);
    long long int y = helpermergesort(a, mid + 1, e);

    long long int z = merge(a, s, mid, e);

    return x + y + z;
}
long long int inversionCount(long long arr[], long long N)
{
    return helpermergesort(arr, 0, N - 1);
}