#include <bits/stdc++.h>
using namespace std;

// prob_link : https://practice.geeksforgeeks.org/problems/common-elements1132/1

// simple implementation problem
//  Time=Space : O(n1 + n2 + n3)

vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3)
{
    int i = 0, j = 0, k = 0, prev = 0; // for A-B-C and to avoid duplicate(prev)
    vector<int> ans;

    while (i < n1 and j < n2 and k < n3)
    {
        if (A[i] == B[j] and A[i] == C[k] and A[i] != prev)
        {
            ans.push_back(A[i]);
            prev = A[i];
            i++;
            j++;
            k++;
        }

        else if (A[i] < B[j])
            i++; // A will be left behind
        else if (B[j] < C[k])
            j++; // B will be left behind
        else
            k++; // C is smallest and will be left behind
    }

    return ans;
}