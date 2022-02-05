#include <bits/stdc++.h>
using namespace std;

// prob_link : https://practice.geeksforgeeks.org/problems/factorials-of-large-numbers2508/1

//  Factorial of large number cannot be stored in any data types
//  So we use use array for the same multiplication is done carefully at root level

void multiply(vector<int> &ans, int x)
{
    int carry = 0;
    int n = ans.size();
    for (int i = 0; i < n; i++)
    {
        int prod = x * ans[i] + carry;
        ans[i] = prod % 10;
        carry = prod / 10;
    }

    while (carry)
    {
        ans.push_back(carry % 10);
        carry /= 10;
    }
}

vector<int> factorial(int N)
{
    vector<int> ans;
    ans.push_back(1);

    for (int i = 2; i <= N; i++)
        multiply(ans, i);

    reverse(ans.begin(), ans.end());

    return ans;
}