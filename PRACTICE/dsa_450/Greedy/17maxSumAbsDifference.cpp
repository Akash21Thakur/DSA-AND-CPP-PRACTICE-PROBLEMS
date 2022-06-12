#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Problem: find the permutation that gives the maximum sum of the difference of element
// Approach:  T(nlogn),S(n)
//    arrange arrage as small big small big so on...
// needs sorting

int maxSum(vector<int> &v)
{
    int n = v.size();
    sort(v.begin(), v.end());

    vector<int> temp;
    // insert alternately small and big
    for (int i = 0; i < n / 2; i++)
    {
        temp.push_back(v[i]);
        temp.push_back(v[n - i - 1]);
    }

    // when n is odd
    if (n & 1)
        temp.push_back(v[n / 2]);

    int ans = 0;
    for (int i = 0; i < n - 1; i++)
        ans += abs(temp[i] - temp[i + 1]);

    // diff of first and last
    ans += abs(temp[0] - temp[n - 1]);

    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    cout << "Maximum Sum Absolute Difference : " << maxSum(v);
}