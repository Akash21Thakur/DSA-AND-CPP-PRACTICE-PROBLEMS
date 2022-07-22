#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> s;
    vector<int> ans(n, -1);
    for (int i = n - 1; i >= 0; i++)
    {
        while (!s.empty() and s.top() >= arr[i])
            s.pop();
        if (!s.empty())
            //             ans[i]=-1;
            //         else
            ans[i] = arr[i];
        s.push(arr[i]);
    }
    return ans;
}