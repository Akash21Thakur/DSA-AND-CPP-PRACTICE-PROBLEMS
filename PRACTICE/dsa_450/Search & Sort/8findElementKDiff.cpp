#include <iostream>
#include <vector>
using namespace std;

int findElement(vector<int> &v, int x, int k)
{
    int n = v.size();
    int i = 0;

    while (i < n)
    {
        if (v[i] == x)
            return i;

        i = i + max(1, abs(v[i] - x) / k);
    }

    return -1;
}

int main()
{
    int x, k, n;
    cin >> x >> k >> n;
    vector<int> v;
    int t;

    for (int i = 0; i < n; i++)
    {
        cin >> t;
        v.push_back(t);
    }

    cout << findElement(v, x, k);
}