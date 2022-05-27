// Minimum swap required to convert binary tree to binary search tree
// Given the array representation of Complete Binary Tree i.e, if index i is the parent, index 2*i + 1 is the left child and index 2*i + 2 is the right child.
// The task is to find the minimum number of swap required to convert it into Binary Search Tree.

// The idea is to use the fact that inorder traversal of Binary Search Tree is in increasing order of their value.
// So, find the inorder traversal of the Binary Tree and store it in the array and try to sort the array.
// The minimum number of swap required to get the array sorted will be the answer.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void inorder(int idx, int n, int *a, vector<int> &v)
{
    if (idx >= n)
        return;

    // left
    inorder(idx * 2 + 1, n, a, v);
    // root
    v.push_back(a[idx]);
    // right
    inorder(idx * 2 + 2, n, a, v);
}

int minSwaps(vector<int> &v)
{
    vector<pair<int, int>> t(v.size());
    int ans = 0;

    for (int i = 0; i < v.size(); i++)
    {
        t[i].first = v[i];
        t[i].second = i;
    }

    sort(t.begin(), t.end());

    // campare the sorted ones index

    for (int i = 0; i < v.size(); i++)
    {
        if (i == t[i].second)
            continue;
        else
        {
            swap(t[i].first, t[t[i].second].first);
            swap(t[i].second, t[t[i].second].second);
        }

        ans++;

        --i;
    }
    return ans;
}

int main()
{
    int a[] = {1, 2, 3};
    int n = sizeof(a) / sizeof(a[0]);
    std::vector<int> v;
    inorder(0, n, a, v);
    cout << minSwaps(v) << endl;
}
