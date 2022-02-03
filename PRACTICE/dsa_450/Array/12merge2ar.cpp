#include <bits/stdc++.h>
using namespace std;

// prob_link : https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays5135/1

// METHOD-1 -->Time : O(n*m) , Space : O(1)
//  algo : gives(tle in gfg :{ )
//  --> swap if ar1>ar2 and always keep ar2 sorted

void insertionSort(int *b, int m)
{
    for (int i = 1; i < m; i++)
    {
        if (b[i] < b[i - 1])
            swap(b[i], b[i - 1]);
        else
            break;
    }
}
void merge(int a[], int b[], int n, int m)
{

    for (int i = 0; i < n; i++)
    {
        if (a[i] > b[0])
        {
            swap(a[i], b[0]);
            insertionSort(b, m);
        }
    }
}

// METHOD-2  Time : (m+n)log(m+n) , Space : O(1)
// GAP METHOD
// create a gap and swap if first>second (second-first=gap)
// gap=gap/2 every time

int nextGap(int gap)
{
    if (gap <= 1)
        return 0;
    return (gap / 2) + (gap % 2);
}

void merge(int *a, int *b, int n, int m)
{
    int i, j, gap = n + m;

    for (gap = nextGap(gap); gap > 0; gap = nextGap(gap))
    {
        for (i = 0; i + gap < n; i++)
            if (a[i] > a[i + gap])
                swap(a[i], a[i + gap]);

        for (j = gap > n ? gap - n : 0; i < n and j < m; i++, j++)
            if (a[i] > b[j])
                swap(a[i], b[j]);

        if (j < m)
        {
            for (j = 0; j + gap < m; j++)
                if (b[j] > b[j + gap])
                    swap(b[j], b[j + gap]);
        }
    }
}