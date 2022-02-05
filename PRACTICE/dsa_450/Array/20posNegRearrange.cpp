#include <iostream>
using namespace std;

// METHOD-1   Time : O(n)  , Space : O(n)
//------------Ordered is maintained----------
//  1. simply take two array pos and neg...add the element resp.
//  2. add back to the original array alternating the pos-neg value

// METHOD-2   Time : O(n)  , Space : O(1)
//  -------Order not mainatined----------
//  1. Bring pos. to one side and neg to the other
//  2. Swap the element as needed

void rearrangeUnordered(int *a, int n)
{
    int i = 0, j = n - 1;

    // bring pos to front
    while (i < j)
    {
        if (a[i] < 0)
            swap(a[i], a[j--]);
        else
            i++;
    }

    // if all neg or pos
    if (i == 0 or i == n)
        return;

    // i has the first index where the negative element starts to end
    // placing the element to its correct order----neg_pos_neg_pos...
    int k = 0;
    while (i < n and k < n and k < i)
    {
        swap(a[k], a[i]);
        k = k + 2;
        i = i + 1;
    }
}

// METHOD-3 Time : O(n^2)  , Space : O(1)
// ---------ORDER IS MAINTAINED----------
// 1. Find the first out-of-place index in the array :
//     -->out-of-place : neg in odd place (1,3,5,...)
//                       pos in even place (0,2,4,....)
// 2. If found search for next index with opposite sign...and rotate the array(out-of-place,oppSignIdx)
// 3. Update out-of-place index accordingly
// ----Try Out With Pen/Paper for clarity--------

void rotateAry(int *a, int start, int end)
{
    int temp = a[end];
    for (int i = end - 1; i >= start; i--)
        a[i + 1] = a[i];
    a[start] = temp;
}

void rearrangeOrdered(int *a, int n)
{
    int outofplace = -1;

    for (int i = 0; i < n; i++)
    {
        if (outofplace >= 0)
        {
            if ((a[outofplace] >= 0 and a[i] < 0) or (a[outofplace] < 0 and a[i] >= 0))
            {
                // 2.
                rotateAry(a, outofplace, i);

                // 3.
                if (i - outofplace >= 2)
                    outofplace = i + 2;
                else
                    outofplace = -1;
            }
        }
        else
        {
            // 1.
            if ((a[i] >= 0 and i % 2 == 0) or (a[i] < 0 and i % 2 == 1))
                outofplace = i;
        }
    }
}

void printary(int *a, int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}
int main()
{
    int n;
    cout << "Size : ";
    cin >> n;
    int a[n];
    cout << "Enter elements : ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    // printary(a, n);
    // rearrangeUnordered(a, n);
    printary(a, n);
    rearrangeOrdered(a, n);
    printary(a, n);
}