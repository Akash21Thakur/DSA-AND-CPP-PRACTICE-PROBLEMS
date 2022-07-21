#include <iostream>
#include <vector>
using namespace std;

int findMed(int *arr1, int *arr2, int n)
{
    int i = 0; // ar1 index
    int j = 0; // ar2 index

    int m1 = -1, m2 = -1; // median cur and prev
    for (int count = 0; count <= n; count++)
    {
        // if ar1 largest < ar2 smallest
        if (i == n)
        {
            m1 = m2;
            m2 = arr2[0];
            break;
        }

        // if ar2 largest < ar1 smallest
        if (j == n)
        {
            m1 = m2;
            m2 = arr1[0];
            break;
        }

        if (arr1[i] <= arr2[j])
        {
            m1 = m2;      // store the prev median
            m2 = arr1[i]; // current median
            i++;
        }
        else
        {
            m1 = m2;      // store the prev median
            m2 = arr2[j]; // current median
            j++;
        }
    }

    return (m1 + m2) / 2;
}
