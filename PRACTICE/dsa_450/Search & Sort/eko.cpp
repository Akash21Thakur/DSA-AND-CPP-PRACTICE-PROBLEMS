#include <iostream>
#include <vector>
#include <climits>
using namespace std;

#define ll long long int

bool isPossible(vector<ll> &v, ll m, ll limit)
{
    ll sum = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] > limit)
            sum += (v[i] - limit);
    }

    if (sum >= m)
        return true;
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<ll> v(n);

    ll maxi = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        maxi = max(maxi, v[i]);
    }

    ll low = 0, high = maxi, res = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (isPossible(v, m, mid))
        {
            res = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }

    cout << res << endl;
}