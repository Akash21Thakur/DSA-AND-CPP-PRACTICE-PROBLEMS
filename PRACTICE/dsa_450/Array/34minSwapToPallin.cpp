#include <bits/stdc++.h>
using namespace std;

// merge count increase when number of a[first-1]!=a[last-1]
// so we merge the side which is smaller with its immediate next element
// as it gives a possibily to make pallinpr

int minSwaps(vector<int> &v, int n)
{
    int count = 0;

    int i = 0, j = n - 1;
    int ans = 0;

    while (i < j)
    {
        if (v[i] == v[j])
        {
            i++;
            j--;
        }
        else if (v[i] < v[j])
        {
            i++;
            v[i] += v[i - 1];
            ans++;
        }
        else
        {
            j--;
            v[j] += v[j + 1];
            ans++;
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v;

    for (int i = 0; i < n; i++)
        cin >> v[i];

    cout << minSwaps(v, n);
}